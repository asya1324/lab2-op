#include <iostream>
#include <vector>
#include <cmath>
#include "Funtr.h"

using namespace std;

int main() 
{

    char op;

    do {
        cout << "Вітаю. Введіть вершини трикутника: " << endl;
        Triangle tr;
        cin >> tr.A.x >> tr.A.y;
        cin >> tr.B.x >> tr.B.y;
        cin >> tr.C.x >> tr.C.y;

        vector<Point> tochki;

        cout << "Введіть кількість точок: " << endl;
        int q;
        cin >> q;
        while(q<1){
            cout << "Кількість точок не може бути від'ємною. Try again: ";
            cin >> q;
        }

        cout << "Введіть точки: " << endl;
        for(int j = q; j > 0; j--){
            Point Bert;
            cin >> Bert.x;
            cin >> Bert.y;
            tochki.push_back(Bert);
        }

        cout << "1. Перевірка чи належить точка трикутнику(формула герона) " << endl;
        cout << "2. Перевірка чи належить точка трикутнику(векторний добуток) " << endl;
        
        int choice = 0;
        cout << "Вибір: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if (tr.degtr()) {
                    cout << "Трикутник вироджений." << endl;
                    for (Point Bert : tochki){
                        if (tr.storcheck(Bert)) 
                            cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику та лежить на його межі" << endl;
                       else 
                            cout << "Точка " << Bert.x  << " " << Bert.y << " не належить трикутнику" << endl;
                   }
                }
                    
                else{
                    cout << "Трикутник not вироджений." << endl;
                    for (Point Bert : tochki){
                        if (tr.contains(Bert)) {
                            if (tr.storcheck(Bert)) 
                                cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику та лежить на його межі" << endl;
                            else 
                                cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику, але не лежить на його межі" << endl;
                        }
                       else
                            cout << "Точка " << Bert.x  << " " << Bert.y << " не належить трикутнику" << endl;
                   }
                }
                break;
            case 2:
            if (tr.degtr()) {
                cout << "Трикутник вироджений." << endl;
                for (Point Bert : tochki){
                    if (tr.storcheck(Bert)) 
                        cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику та лежить на його межі" << endl;
                   else 
                        cout << "Точка " << Bert.x  << " " << Bert.y << " не належить трикутнику" << endl;
               }
            }
                
            else{
                cout << "Трикутник not вироджений." << endl;
                for (Point Bert : tochki){
                    if (tr.containsvik(Bert)) {
                        if (tr.storcheck(Bert)) 
                            cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику та лежить на його межі" << endl;
                        else 
                            cout << "Точка " << Bert.x  << " " << Bert.y << " належить трикутнику, але не лежить на його межі" << endl;
                    }
                   else
                        cout << "Точка " << Bert.x  << " " << Bert.y << " не належить трикутнику" << endl;
               }
            }
            break;
        }

        cout << "\nЧи ви хочете продовжити? (y/n) ";
        cout << "\nПродовжити? ";
        cin >> op;
    }  while (op == 'y');


    return 0;
}


