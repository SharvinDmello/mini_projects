contacts = {}

def add_contact(name, phone):
    contacts[name] = phone
    print(f"Contact '{name}' added.")

def view_contacts():
    if not contacts:
        print("No contacts to show.")
    else:
        for name, phone in contacts.items():
            print(f"Name: {name}, Phone: {phone}")

def delete_contact(name):
    if name in contacts:
        del contacts[name]
        print(f"Contact '{name}' deleted.")
    else:
        print(f"No contact found with name '{name}'.")

while True:
    print("\nContact Book:")
    print("1. Add Contact")
    print("2. View Contacts")
    print("3. Delete Contact")
    print("4. Exit")
    choice = input("Enter your choice: ")
    
    if choice == '1':
        name = input("Enter contact name: ")
        phone = input("Enter contact phone: ")
        add_contact(name, phone)
    elif choice == '2':
        view_contacts()
    elif choice == '3':
        name = input("Enter contact name to delete: ")
        delete_contact(name)
    elif choice == '4':
        print("thank you!")
        break
    else:
        print("Invalid choice, please try again.")
