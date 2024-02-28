from flask import Flask, render_template, request
import csv
import os

app = Flask(__name__)

@app.route("/", methods=['GET', 'POST'])
def index():

    if request.method == 'POST':
        algorithm_to_render = request.form["algo"]
        
        # Cria o arquivo csv a ser utilizado
        with open("input.csv", "w+") as FILE:
            # Divide as linhas separadas em uma lista
            edges = request.form["edge_list"].splitlines() 
            writer = csv.writer(FILE)

            for line in edges:
                writer.writerow(line[0] + line[2])
        
        render_animation_command = f"manim -qm ~/Documents/CompSci/animations/animation_script.py {algorithm_to_render}"
        os.system(render_animation_command)
        return render_template("video_player.html")
    return render_template("index.html")


