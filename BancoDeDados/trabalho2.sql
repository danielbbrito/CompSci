CREATE TABLE unidadeatendimento (
    codunidatendimento NUMERIC(3) PRIMARY KEY,
    nome VARCHAR(50) UNIQUE NOT NULL,
    endereco VARCHAR(200) NOT NULL
);

CREATE TABLE telefonesunidadeatendimento (
    codtelefone NUMERIC(3) PRIMARY KEY REFERENCES unidadeatendimento(codunidatendimento),
    telefone SMALLINT NOT NULL
);

CREATE TABLE unidadeacademica (
    codunidadeacademica CHAR(4) PRIMARY KEY,
    nome VARCHAR(50) UNIQUE NOT NULL
);

CREATE TABLE curso (
    codcurso NUMERIC(3) PRIMARY KEY,
    nome VARCHAR(50) UNIQUE NOT NULL,
    codunidade CHAR(4) REFERENCES unidadeacademica(codunidadeacademica)
);

CREATE TABLE disciplina (
    coddisciplina CHAR(7) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL
);

CREATE TABLE funcionariobiblioteca (
    matricula NUMERIC(5) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    funcao VARCHAR(50) NOT NULL CHECK (funcao IN ('bibliotecario', 'atendente')),
    codunidade INT REFERENCES unidadeatendimento(codunidatendimento),
    CHECK (
        (funcao = 'bibliotecario' AND codunidade IS NULL) OR
        (funcao = 'atendente' AND codunidade IS NOT NULL)
    )
);

CREATE TABLE tituloacervo (
    isbn NUMERIC(5) PRIMARY KEY,
    nometitulo VARCHAR(100) NOT NULL,
    areaprincipal VARCHAR(100) NOT NULL,
    assunto VARCHAR(100) NOT NULL,
    anopublicado INT NOT NULL CHECK (anopublicado <= EXTRACT(YEAR FROM CURRENT_DATE) AND anopublicado > 0),
    editora VARCHAR(50) NOT NULL,
    idioma VARCHAR(5) NOT NULL,
    prazoemprestimoprof SMALLINT NOT NULL,
    prazoemprestimoaluno SMALLINT NOT NULL,
    nmaxrenovacao SMALLINT NOT NULL
);

CREATE TABLE areasecundariatitulo (
    codarea NUMERIC(5) PRIMARY KEY REFERENCES tituloacervo(isbn),
    area VARCHAR(100) NOT NULL
);

CREATE TABLE titulolivro (
    codlivro NUMERIC(5) PRIMARY KEY REFERENCES tituloacervo(isbn),
    autor VARCHAR(100) NOT NULL,
    edicao INT NOT NULL
);

CREATE TABLE tituloperiodico (
    codperiodico NUMERIC(5) PRIMARY KEY REFERENCES tituloacervo(isbn),
    periodicidade VARCHAR(15) NOT NULL CHECK (periodicidade IN ('semanal', 'quinzenal', 'mensal', 'trimestral', 'quadrimestral', 'semestral')),
    tipo CHAR(1) NOT NULL CHECK (tipo IN ('J', 'R', 'B'))
);

CREATE TABLE usuariobiblioteca (
    codusuario NUMERIC(5) PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    identidade VARCHAR(12),
    cpf VARCHAR(12),
    sexo CHAR(1) NOT NULL CHECK (sexo IN ('M', 'F')),
    nascimento DATE NOT NULL,
    estadocivil CHAR(1) NOT NULL CHECK (estadocivil IN ('C','S','D','V'))
);

CREATE TABLE telefoneusuario (
    codtelefoneusuario NUMERIC(5) PRIMARY KEY REFERENCES usuariobiblioteca(codusuario),
    telefone NUMERIC(10) NOT NULL
);

CREATE TABLE professor (
    codprofessor NUMERIC(5) PRIMARY KEY REFERENCES usuariobiblioteca(codusuario),
    codunidade CHAR(4) NOT NULL REFERENCES unidadeacademica(codunidadeacademica),
    matriculaprofessor NUMERIC(5) NOT NULL UNIQUE
);

CREATE TABLE aluno (
    codaluno NUMERIC(5) PRIMARY KEY REFERENCES usuariobiblioteca(codusuario)
);

CREATE TABLE alunocursos (
    codcurso NUMERIC(3) REFERENCES curso(codcurso),
    codaluno NUMERIC(5) REFERENCES aluno(codaluno),
    matricula NUMERIC(5) NOT NULL UNIQUE,
    PRIMARY KEY(codcurso, codaluno)
);

CREATE TABLE professordisciplina (
    codprofessor NUMERIC(5) REFERENCES professor(codprofessor),
    coddisciplina CHAR(7) REFERENCES disciplina(coddisciplina),
    PRIMARY KEY(codprofessor, coddisciplina)
);

CREATE TABLE copiatitulo (
    numerocopia NUMERIC(5) PRIMARY KEY NOT NULL,
    isbn NUMERIC(5) REFERENCES tituloacervo(isbn),
    secaocopia NUMERIC(4) NOT NULL,
    estantecopia NUMERIC(3) NOT NULL,
    codatendimento NUMERIC(3) REFERENCES unidadeatendimento(codunidatendimento)
);

CREATE TABLE transacao (
    numerotransacao NUMERIC(9) PRIMARY KEY,
    datatransacao DATE NOT NULL,
    horariotransacao TIME NOT NULL,
    atendente NUMERIC(5) NOT NULL REFERENCES funcionariobiblioteca(matricula),
    tipotransacao VARCHAR(2) NOT NULL CHECK (tipotransacao IN ('E', 'D', 'R', 'RS')),
    codusuario NUMERIC(5) NOT NULL REFERENCES usuariobiblioteca(codusuario)
);

CREATE TABLE itememprestimo (
    numerodevolucao NUMERIC(9) REFERENCES transacao(numerotransacao),
    numeroitem NUMERIC(5) PRIMARY KEY NOT NULL REFERENCES copiatitulo(numerocopia),
    datalimite DATE NOT NULL,
    situacaocopia CHAR(1) NOT NULL CHECK(situacaocopia IN ('I', 'D')),
    multaatraso NUMERIC(7,2),
    multadano NUMERIC(7,2)
);

CREATE TABLE itensrenovados (
    numeroitem NUMERIC(9) REFERENCES itememprestimo(numeroitem),
    numerotransacao NUMERIC(9) REFERENCES transacao(numerotransacao),
    datadevrenovacao DATE NOT NULL,
    PRIMARY KEY(numeroitem, numerotransacao)
);

CREATE TABLE itensreservados (
    numeroitem NUMERIC(9) REFERENCES itememprestimo(numeroitem),
    numerotransacao NUMERIC(9) REFERENCES transacao(numerotransacao),
    datareserva DATE NOT NULL,
    PRIMARY KEY (numeroitem, numerotransacao)
);