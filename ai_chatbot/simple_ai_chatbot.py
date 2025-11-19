def chatbot_response(userinput):
    userinput = userinput.lower()
    if "hello"in userinput or "hi" in userinput:
        return "hi there ! how can i help you"
    elif "name" in userinput :
        return "im a dump ai assistant"
    elif "how are you" in userinput:
        return "im doing very bad no thanks for asking"
    elif "bye" in userinput:
        return "goodbye "
    else :
        return "sorry im to yong to undrstand that"
while True:
    user_input = input("You: ")
    if user_input.lower() == "exit":
        print("AI: Goodbye!")
        break
    print("AI:", chatbot_response(user_input))

