#include <iostream>
using namespace std;

// ������� �����
class Triad {
protected:
    int first, second, third;

public:
    // ����������� ��� ����������
    Triad() {
        first = 0;
        second = 0;
        third = 0;
    }

    // ����������� � �����������
    Triad(int f, int s, int t) {
        first = f;
        second = s;
        third = t;
    }

    // ����������� �����������
    Triad(const Triad& obj) {
        first = obj.first;
        second = obj.second;
        third = obj.third;
    }

    // ����������
    ~Triad() {}

    // ��������� � ������������
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }
    void setThird(int t) { third = t; }

    // ���������� �������� ������������
    Triad& operator=(const Triad& obj) {
        if (this != &obj) {
            first = obj.first;
            second = obj.second;
            third = obj.third;
        }
        return *this;
    }

    // ���������� �������� ����� � ������
    friend istream& operator>>(istream& in, Triad& obj) {
        cout << "������� ������ �����: ";
        in >> obj.first;
        cout << "������� ������ �����: ";
        in >> obj.second;
        cout << "������� ������ �����: ";
        in >> obj.third;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Triad& obj) {
        out << obj.first << ", " << obj.second << ", " << obj.third;
        return out;
    }

    // ������ ��������� ����� � ��������� ������

    bool isEqual(const Triad& obj) const {
        return (first == obj.first && second == obj.second && third == obj.third);
    }
};

// ����������� �����
class Date : public Triad {
public:
    // ����������� ��� ����������
    Date() : Triad() {}

    // ����������� � �����������
    Date(int year, int month, int day) : Triad(year, month, day) {}

    // ����������� �����������
    Date(const Date& obj) : Triad(obj.first, obj.second, obj.third) {}

    // ���������� �������� ������������
    Date& operator=(const Date& obj) {
        if (this != &obj) {
            first = obj.first;
            second = obj.second;
            third = obj.third;
        }
        return *this;
    }

    // ���������� �������� ����� � ������
    friend istream& operator>>(istream& in, Date& obj) {
        cout << "������� ���: ";
        in >> obj.first;
        cout << "������� �����: ";
        in >> obj.second;
        cout << "������� ����: ";
        in >> obj.third;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Date& obj) {
        out << obj.first << "/" << obj.second << "/" << obj.third;
        return out;
    }

    // �������� ��������� ���
    bool operator==(const Date& obj) const {
        return (first == obj.first && second == obj.second && third == obj.third);
    }
    bool operator!=(const Date& obj) const {
        return !(*this == obj);
    }
    bool operator>(const Date& obj) const {
        if (first > obj.first) {
            return true;
        }
        else if (first == obj.first) {
            if (second > obj.second) {
                return true;
            }
            else if (second == obj.second) {
                if (third > obj.third) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<(const Date& obj) const {
        return (!(*this > obj) && !(*this == obj));
    }
    bool operator>=(const Date& obj) const {
        return (*this > obj || *this == obj);
    }
    bool operator<=(const Date& obj) const {
        return (*this < obj || *this == obj);
    }
};

// �������, ���������� � ������������ ������ �������� ������
Triad run(Triad obj) {
    return obj;
}
void print(const Triad& obj) {
    cout << obj << endl;
}

int main() {

    setlocale(0, "");

    // �������� �������� � ������ �� ����� �������������� ����������
    Triad obj1;                        // ����������� ��� ����������
    Triad obj2(1, 2, 3);               // ����������� � �����������
    Triad obj3 = obj2;                 // ����������� �����������
    Triad obj4;
    obj4 = obj1;                       // ���������� �������� ������������

    cout << "������� ������: ";
    cin >> obj1;                       // ���������� �������� �����
    cout << "������: " << obj1 << endl; // ���������� �������� ������


    cout << obj3 << " - �������� ������" << endl;// ����� ��������� �����

    if (obj2.isEqual(obj4) == 0)
        cout << "������ �����" << endl;
    else cout << "������ �� �����" << endl;// ����� ��������� ������

    Date date1;
    Date date2(2021, 10, 1);
    cout << "������� ����: ";
    cin >> date1;

    if (date1 == date2) {
        cout << "���� �����" << endl;
    }
    else if (date1 != date2) {
        cout << "���� �� �����" << endl;
    }

    if (date1 > date2) {
        cout << "���� 1 ����� ��� ���� 2" << endl;
    }
    else if (date1 < date2) {
        cout << "���� 1 ������ ��� ���� 2" << endl;
    }

    //if (date1 >= date2) {
    //    cout << "���� 1 ����� ��� ����� ���� 2" << endl;
    //}
    //else if (date1 <= date2) {
    //    cout << "���� 1 ������ ��� ����� ���� 2" << endl;
    //}

    // ������� �����������
    print(date1);
    Triad obj5 = run(date2);
    cout << obj5 << " - �������� ����" << endl;

    return 0;
}