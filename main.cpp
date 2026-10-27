#include <iostream>
#include <string>
using namespace std;

struct Movie
{
    int id;
    string name;
    int price;
};

Movie movies[3] = {
    {1, "Pushpa 2", 150},
    {2, "Stree 2", 150},
    {3, "Chhava", 150}};

void showMovies()
{

    cout << "\n====================================\n";
    cout << "       AVAILABLE MOVIES\n";
    cout << "====================================\n";

    for (int i = 0; i < 3; i++)
    {
        cout << movies[i].id << ". "
             << movies[i].name
             << " - Rs." << movies[i].price
             << endl;
    }
}

int calculateAmount(int movieId, int tickets)
{

    if (movieId < 1 || movieId > 3)
    {
        return 0;
    }

    return movies[movieId - 1].price * tickets;
}

void bookTicket()
{

    int movieId;
    int tickets;
    string seat;
    string payment;

    showMovies();

    cout << "\nEnter Movie ID: ";
    cin >> movieId;

    if (movieId < 1 || movieId > 3)
    {
        cout << "Invalid Movie ID!\n";
        return;
    }

    cout << "Enter Number of Tickets: ";
    cin >> tickets;

    if (tickets <= 0)
    {
        cout << "Invalid ticket quantity!\n";
        return;
    }

    cout << "Enter Seat Number: ";
    cin >> seat;

    cout << "Enter Payment Method: ";
    cin >> payment;

    int total = calculateAmount(movieId, tickets);

    cout << "\n====================================\n";
    cout << "          BOOKING RECEIPT\n";
    cout << "====================================\n";

    cout << "Movie       : "
         << movies[movieId - 1].name << endl;

    cout << "Ticket Price: Rs."
         << movies[movieId - 1].price << endl;

    cout << "Tickets     : "
         << tickets << endl;

    cout << "Seat        : "
         << seat << endl;

    cout << "Payment     : "
         << payment << endl;

    cout << "Total       : Rs."
         << total << endl;

    cout << "====================================\n";

    cout << "Booking Successful!\n";
}

int main()
{

    int choice;

    cout << "====================================\n";
    cout << "   MOVIE TICKET MANAGEMENT SYSTEM\n";
    cout << "====================================\n";

    while (true)
    {

        cout << "\n1. Show Movies";
        cout << "\n2. Book Ticket";
        cout << "\n3. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            showMovies();
            break;

        case 2:
            bookTicket();
            break;

        case 3:
            cout << "\nThank you!\n";
            return 0;

        default:
            cout << "\nInvalid choice!\n";
        }
    }

    return 0;
}