#include <iostream>
#include <ctime>
using namespace std;

class tic_tac_toe
{
private:
    string name1, name2;

protected:
    char *arr0;
    int *arr1;
    int *arr2;

public:
    int pos, count = 0;
    char sym1, sym2;

    tic_tac_toe()
    {

        arr0 = new char[9];
        arr1 = new int[9];
        arr2 = new int[9];
        for (int i = 0; i < 9; i++)
        {
            arr0[i] = ' ';
            arr1[i] = 0;
            arr2[i] = 0;
        }
        cout << "Game Begin" << endl;
    }

    friend void operator>>(istream &input, tic_tac_toe &s)
    {
        cout << "Enter name player 1: ";
        input >> s.name1;
        cout << "Enter name player 2: ";
        input >> s.name2;
        cout << "Choose your(" << s.name1 << ") symbol(O, X): ";
        cin >> s.sym1;
        s.sym2 = (s.sym1 == 'X') ? 'O' : 'X';
    }
    bool call();
    friend bool winner(int n, int *arr);
    void display();
    void Initial_display();
    ~tic_tac_toe()
    {
        cout << "Game ended" << endl;
    }
};

class computer : public tic_tac_toe
{
    bool flag;
    string name;

public:
    friend void operator>>(istream &input, computer &s)
    {
        cout << "Enter your name: ";
        input >> s.name;
        cout << "Choose your(" << s.name << ") symbol(O, X): ";
        cin >> s.sym1;
        s.sym2 = (s.sym1 == 'X') ? 'O' : 'X';
    }
    void turn()
    {
        int t;
        cout << "Enter 1 to specify whether you want to go first else 2: ";
        cin >> t;
        if (t == 1)
            flag = true;
        else
            flag = false;
    }
    bool call();
};

bool winner(int n, int *arr);
bool computer ::call()
{
    if (flag)
    {
    to1:
        cout << "Choose pos " << name << " : ";
        cin >> pos;
        if (arr0[pos - 1] == ' ')
        {
            if (pos >= 1 && pos <= 9)
            {
                arr0[pos - 1] = sym1;
                arr1[pos - 1]++;
                display();
                if (winner(pos - 1, arr1))
                {
                    cout << name << endl;
                    return true;
                }
                count++;
                if (count < 9)
                {
                to:
                    srand(time(NULL));
                    pos = rand() % 9 + 1;
                    while (arr0[pos - 1] != ' ')
                    {
                        srand(time(NULL));
                        pos = rand() % 9 + 1;
                    }
                    if (arr0[pos - 1] == ' ')
                    {
                        arr0[pos - 1] = sym2;
                        arr2[pos - 1]++;
                        cout << endl
                             << "Computer's turn" << endl;
                        display();
                        if (winner(pos - 1, arr2))
                        {
                            cout << "Computer" << endl;
                            return true;
                        }
                        count++;
                    }
                    else
                    {
                        cout << "Invalid position" << endl;
                        goto to;
                    }
                }
            }
        }
        else
        {
            cout << "Invalid position" << endl;
            goto to1;
        }
        return false;
    }
    else
    {
        if (count < 9)
        {
            srand(time(NULL));
            pos = rand() % 9 + 1;
            while (arr0[pos - 1] != ' ')
            {
                srand(time(NULL));
                pos = rand() % 9 + 1;
            }
            arr0[pos - 1] = sym2;
            arr2[pos - 1]++;
            cout << endl
                 << "Computer's turn" << endl;
            display();
            if (winner(pos - 1, arr2))
            {
                cout << "Computer" << endl;
                return true;
            }
            count++;
            if (count < 9)
            {
            to3:
            to4:
                cout << "Choose pos " << name << " : ";
                cin >> pos;
                if (arr0[pos - 1] == ' ')
                {
                    if (pos >= 1 && pos <= 9)
                    {
                        arr0[pos - 1] = sym1;
                        arr1[pos - 1]++;
                        display();
                        if (winner(pos - 1, arr1))
                        {
                            cout << name << endl;
                            return true;
                        }
                        count++;
                    }
                    else
                    {
                        cout << "Invalid position" << endl;
                        goto to3;
                    }
                }
                else
                {
                    cout << "Invalid position" << endl;
                    goto to4;
                }
            }
        }
        return false;
    }
    return false;
}

bool tic_tac_toe::call()
{
to1:
    cout << "Choose pos " << name1 << " : ";
    cin >> pos;
    if (arr0[pos - 1] == ' ')
    {
        if (pos >= 1 && pos <= 9)
        {
            arr0[pos - 1] = sym1;
            arr1[pos - 1]++;
            display();
            if (winner(pos - 1, arr1))
            {
                cout << name1 << endl;
                return true;
            }
            count++;
            if (count < 9)
            {
            to:
                cout << "Choose pos " << name2 << " : ";
                cin >> pos;
                if (arr0[pos - 1] == ' ')
                {
                    arr0[pos - 1] = sym2;
                    arr2[pos - 1]++;
                    display();
                    if (winner(pos - 1, arr2))
                    {
                        cout << name2 << endl;
                        return true;
                    }
                    count++;
                }
                else
                {
                    cout << "Invalid position" << endl;
                    goto to;
                }
            }
        }
    }
    else
    {
        cout << "Invalid position" << endl;
        goto to1;
    }
    return false;
}

bool winner(int n, int *arr)
{
    int p = n % 3;
    switch (p)
    {
    case 0:
        if (arr[n + 2] && arr[n + 1])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    case 1:
        if (arr[n - 1] && arr[n + 1])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    case 2:
        if (arr[n - 2] && arr[n - 1])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    }
    int p1 = n / 3;
    switch (p1)
    {
    case 0:
        if (arr[n + 3] && arr[n + 6])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    case 1:
        if (arr[n - 3] && arr[n + 3])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    case 2:
        if (arr[n - 3] && arr[n - 6])
        {
            cout << "Winner" << endl;
            return true;
        }
        break;
    }
    switch (p1)
    {
    case 0:
        if (p == 0)
        {
            if (arr[n + 4] && arr[n + 8])
            {
                cout << "Winnner" << endl;
                return true;
            }
        }
        if (p == 2)
        {
            if (arr[n + 2] && arr[n + 4])
            {
                cout << "Winnner" << endl;
                return true;
            }
        }
        break;
    case 1:
        if (p == 1)
        {
            if (arr[n - 4] && arr[n + 4])
            {
                cout << "Winnner" << endl;
                return true;
            }
            if (arr[n - 2] && arr[n + 2])
            {
                cout << "Winnner" << endl;
                return true;
            }
        }
        break;
    case 2:
        if (p == 0)
        {
            if (arr[n - 4] && arr[n - 2])
            {
                cout << "Winnner" << endl;
                return true;
            }
        }
        if (p == 2)
        {
            if (arr[n - 4] && arr[n - 8])
            {
                cout << "Winnner" << endl;
                return true;
            }
        }
        break;
    }
    return false;
}

void tic_tac_toe::Initial_display()
{
    int n1 = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 1 || i == 3)
                cout << "--";
            else if (j == 1 || j == 3)
                cout << "| ";
            else
            {
                cout << n1 + 1 << " ";
                n1++;
            }
        }
        cout << endl;
    }
}

void tic_tac_toe::display()
{
    int n1 = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 1 || i == 3)
                cout << "--";
            else if (j == 1 || j == 3)
                cout << "| ";
            else
            {
                if (arr0[n1] == ' ')
                    cout << "-"
                         << " ";
                else
                    cout << arr0[n1] << " ";
                n1++;
            }
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    cout << "Enter 1 for player vs computer\n 2 for player vs player: ";
    cin >> choice;
    if (choice == 1)
    {
        computer t;
        t.Initial_display();
        cin >> t;
        t.turn();
        do
        {
            if (t.call())
                break;

        } while (t.count < 9);

        if (t.count == 9)
            cout << "Draw" << endl;
    }
    else if (choice == 2)
    {
        tic_tac_toe t;
        t.Initial_display();
        cin >> t;
        do
        {
            if (t.call())
                break;

        } while (t.count < 9);

        if (t.count == 9)
            cout << "Draw" << endl;
    }
    else
        cout << "Invalid choice\n";
    return 0;
}