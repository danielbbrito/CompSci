def time_difference(start, end):
    if start is None or end is None:
        return 0
    
    start_hours, start_minutes = start.split(":")
    end_hours, end_minutes = end.split(":")

    st = int(start_hours) * 60 + int(start_minutes)
    ed = int(end_hours) * 60 + int(end_minutes)

    if ed >= st:
        difference = ed - st
    else:
        # If the end time is on the next day
        difference = (24 * 60 - st) + ed

    return difference


print(time_difference("04:29", "07:07"))