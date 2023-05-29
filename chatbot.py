# Simple Customer Interaction Chatbot

# Define a dictionary of predefined responses
responses = {
    "greeting": "Hello! How can I assist you today?",
    "how_are_you": "I'm doing well, thank you for asking!",
    "goodbye": "Goodbye! Have a great day!",
    "thanks": "You're welcome!",
    "name": "My name is Chatbot. Nice to meet you!",
    "age": "I'm an AI chatbot, so I don't have an age.",
    "default": "I'm sorry, I didn't understand. Could you please rephrase that?"
}

# Function to generate a response based on user input
def generate_response(user_input):
    user_input = user_input.lower()
    if "hello" in user_input or "hi" in user_input:
        return responses["greeting"]
    elif "how are you" in user_input:
        return responses["how_are_you"]
    elif "bye" in user_input or "goodbye" in user_input:
        return responses["goodbye"]
    elif "thank" in user_input:
        return responses["thanks"]
    elif "name" in user_input:
        return responses["name"]
    elif "age" in user_input:
        return responses["age"]
    else:
        return responses["default"]

# Main interaction loop
print("Bot: " + responses["greeting"])
while True:
    user_input = input("User: ")
    response = generate_response(user_input)
    print("Bot: " + response)
