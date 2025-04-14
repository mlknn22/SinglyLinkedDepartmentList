#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
using namespace std;

struct Department
{
    string name; // название кафедры
    string fiohead; // ФИО заведующего
    int num_teachers = 0; // количество преподавателей
    int room = 0; // аудитория
    int corpus = 0; // корпус
    Department* next = nullptr; // указатель на следующую кафедру
};

// функция для добавления кафедры в начало списка
void addDepartmentToFront(Department*& head)
{
    Department* newDepartment = new Department;
    cout << "\nВведите название кафедры: ";
    cin.ignore();
    getline(cin, newDepartment->name);
    cout << "Введите ФИО заведующего: ";
    getline(cin, newDepartment->fiohead);
    cout << "Введите количество преподавателей: ";
    cin >> newDepartment->num_teachers;
    cout << "Введите аудиторию: ";
    cin >> newDepartment->room;
    cout << "Введите номер корпуса: ";
    cin >> newDepartment->corpus;
    newDepartment->next = head;
    head = newDepartment;
}

// функция для добавления кафедры в конец списка
void addDepartmentToBack(Department*& head)
{
    if (head == nullptr) // если список пуст, добавляем кафедру в начало списка
    {
        addDepartmentToFront(head);
        return;
    }
    Department* newDepartment = new Department;
    cout << "\nВведите название кафедры: ";
    cin.ignore();
    getline(cin, newDepartment->name);
    cout << "Введите ФИО заведующего: ";
    getline(cin, newDepartment->fiohead);
    cout << "Введите количество преподавателей: ";
    cin >> newDepartment->num_teachers;
    cout << "Введите аудиторию: ";
    cin >> newDepartment->room;
    cout << "Введите номер корпуса: ";
    cin >> newDepartment->corpus;
    Department* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newDepartment;
}

// функция для добавления кафедры после определенной кафедры
void addDepartmentAfter(Department*& head)
{
    if (head == nullptr) // если список пуст, добавляем кафедру в начало списка
    {
        addDepartmentToFront(head);
        return;
    }
    string departmentName;
    cout << "\nВведите название кафедры, после которой нужно добавить новую кафедру: ";
    cin.ignore();
    getline(cin, departmentName);
    Department* current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->name == departmentName)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) // если не нашли кафедру, выводим сообщение и выходим
    {
        cout << "\nКафедра с таким названием не найдена!" << endl;
        return;
    }
    Department* newDepartment = new Department;
    cout << "\nВведите название кафедры: ";
    getline(cin, newDepartment->name);
    cout << "Введите ФИО заведующего: ";
    getline(cin, newDepartment->fiohead);
    cout << "Введите количество преподавателей: ";
    cin >> newDepartment->num_teachers;
    cout << "Введите аудиторию: ";
    cin >> newDepartment->room;
    cout << "Введите номер корпуса: ";
    cin >> newDepartment->corpus;
    newDepartment->next = current->next;
    current->next = newDepartment;
}

// Функция добавления кафедры перед определённой кафедрой
void addDepartmentBefore(Department*& head)
{
    if (head == nullptr) // если список пуст, добавляем кафедру в начало списка
    {
        addDepartmentToFront(head);
        return;
    }
    string departmentName;
    cout << "\nВведите название кафедры, перед которой нужно добавить новую кафедру: ";
    cin.ignore();
    getline(cin, departmentName);
    if (head->name == departmentName) // если добавляем перед первой кафедрой
    {
        addDepartmentToFront(head);
        return;
    }
    Department* current = head;
    bool found = false;
    while (current->next != nullptr)
    {
        if (current->next->name == departmentName)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) // если не нашли кафедру, выводим сообщение и выходим
    {
        cout << "\nКафедра с таким названием не найдена!" << endl;
        return;
    }
    Department* newDepartment = new Department;
    cout << "\nВведите название кафедры: ";
    getline(cin, newDepartment->name);
    cout << "Введите ФИО заведующего: ";
    getline(cin, newDepartment->fiohead);
    cout << "Введите количество преподавателей: ";
    cin >> newDepartment->num_teachers;
    cout << "Введите аудиторию: ";
    cin >> newDepartment->room;
    cout << "Введите номер корпуса: ";
    cin >> newDepartment->corpus;
    newDepartment->next = current->next;
    current->next = newDepartment;
}

// функция для удаления кафедры из списка
void deleteDepartment(Department*& head)
{
    string departmentName;
    cout << "\nВведите название кафедры, которую нужно удалить: ";
    cin.ignore();
    getline(cin, departmentName);
    if (head->name == departmentName) // если удаляем первую кафедру
    {
        Department* temp = head;
        head = head->next;
        delete temp;
        cout << "\nКафедра успешно удалена." << endl;
        return;
    }
    Department* current = head;
    bool found = false;
    while (current->next != nullptr)
    {
        if (current->next->name == departmentName)
        {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) // если не нашли кафедру, выводим сообщение и выходим
    {
        cout << "\nКафедра с таким названием не найдена!" << endl;
        return;
    }
    Department* temp = current->next;
    current->next = temp->next;
    delete temp;
    cout << "\nКафедра успешно удалена." << endl;
}

// Функция для вывода всех кафедр
void printAll(Department*& head)
{
    if (head == nullptr)
    {
        cout << "\nСписок кафедр пуст!" << endl;
        return;
    }
    Department* current = head;
    cout << "\nКафедры: " << endl;
    while (current != nullptr)
    {
        cout << "\nНазвание кафедры: " << current->name << endl;
        cout << "ФИО заведующего: " << current->fiohead << endl;
        cout << "Количество преподавателей: " << current->num_teachers << endl;
        cout << "Аудитория: " << current->room << endl;
        cout << "Корпус: " << current->corpus << endl;
        current = current->next;
    }
}

// Функция для сохранения списка в бинарный файл
void saveDepartmentsToFile(Department*& head)
{
    string filename;
    cout << "\nВведите имя файла: ";
    cin.ignore();
    getline(cin, filename);
    ofstream file(filename, ios::binary);
    if (file) {
        Department* current = head;
        while (current != nullptr)
        {
            file.write((char*)current, sizeof(Department)); // Записываем структуру в файл
            current = current->next;
        }
        file.close();
        cout << "\nДанные списка успешно сохранены в бинарный файл!" << endl;
    }
    else
    {
        cout << "\nНе удалось открыть файл для записи!" << endl;
        return;
    }
}

//функция для вывода сведений о кафедрах определённого корпуса
void printDepartmentsInCorpus(Department*& head)
{
    int corpusNumber;
    cout << "\nВведите номер корпуса: ";
    cin >> corpusNumber;
    Department* current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->corpus == corpusNumber)
        {
            found = true;
            cout << "\nНазвание кафедры: " << current->name << endl;
            cout << "ФИО заведующего: " << current->fiohead << endl;
            cout << "Количество преподавателей: " << current->num_teachers << endl;
            cout << "Аудитория: " << current->room << endl;
            cout << "Корпус: " << current->corpus << endl;
        }
        current = current->next;
    }

    if (found == false)
    {
        cout << "\nКафедры в корпусе " << corpusNumber << " не найдены!" << endl;
    }
}

//функция для вывода сведений о кафедрах по указанному диапазону аудиторий
void printDepartmentsInRoomRange(Department*& head)
{
    int minRoom, maxRoom;
    cout << "\nВведите левую границу диапазона аудиторий: ";
    cin >> minRoom;
    cout << "Введите правую границу диапазона аудиторий: ";
    cin >> maxRoom;
    Department* current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->room >= minRoom && current->room <= maxRoom)
        {
            found = true;
            cout << "\nНазвание кафедры: " << current->name << endl;
            cout << "ФИО заведующего: " << current->fiohead << endl;
            cout << "Количество преподавателей: " << current->num_teachers << endl;
            cout << "Аудитория: " << current->room << endl;
            cout << "Корпус: " << current->corpus << endl;
        }
        current = current->next;
    }
    if (found == false)
    {
        cout << "\nКафедры в заданном диапазоне аудиторий не найдены!" << endl;
    }
}

//функция для вывода сведений о кафедре с максимальным количеством преподавателей
void printDepartmentWithMaxTeachers(Department*& head)
{
    if (head == nullptr)
    {
        cout << "\nСписок кафедр пуст!" << endl;
        return;
    }
    Department* current = head;
    Department* maxDepartment = head;
    while (current != nullptr)
    {
        if (current->num_teachers > maxDepartment->num_teachers)
        {
            maxDepartment = current;
        }
        current = current->next;
    }
    cout << "\nКафедра с максимальным количеством преподавателей: " << endl;
    cout << "Название кафедры: " << maxDepartment->name << endl;
    cout << "ФИО заведующего: " << maxDepartment->fiohead << endl;
    cout << "Количество преподавателей: " << maxDepartment->num_teachers << endl;
    cout << "Аудитория: " << maxDepartment->room << endl;
    cout << "Корпус: " << maxDepartment->corpus << endl;
}

//функция извлечения данных из бинарного файла и помещение новых кафедр в список
void loadDepartmentsFromFile(Department*& head)
{
    string filename;
    cout << "\nВведите имя файла: ";
    cin.ignore();
    getline(cin, filename);
    ifstream file(filename, ios::binary);
    if (file)
    {
        while (!file.eof())
        {
            Department* newDepartment = new Department;
            file.read((char*)newDepartment, sizeof(Department)); // Читаем данные из файла в структуру
            if (file.eof()) // Если достигли конца файла, выходим из цикла
            {
                break;
            }
            newDepartment->next = nullptr;
            if (head == nullptr) // Если список пуст, добавляем первую кафедру
            {
                head = newDepartment;
            }
            else
            {
                Department* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = newDepartment; // Добавляем новую кафедру в конец списка
            }
        }
        file.close();
        cout << "\nДанные из бинарного файла успешно загружены в список!" << endl;
    }
    else
    {
        cout << "\nНе удалось открыть файл для чтения!" << endl;
        return;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Department* head = nullptr;
    int choice;
    // Вывод меню
    cout << "МЕНЮ ДЛЯ РАБОТЫ СО СПИСКОМ: " << endl;
    cout << "1. Вывод всех кафедр" << endl;
    cout << "2. Добавление кафедры в начало списка" << endl;
    cout << "3. Добавление кафедры в конец списка" << endl;
    cout << "4. Добавление кафедры после определенной кафедры" << endl;
    cout << "5. Добавление кафедры перед определенной кафедрой" << endl;
    cout << "6. Удаление кафедры из списка" << endl;
    cout << "7. Вывод сведений о кафедрах определённого корпуса" << endl;
    cout << "8. Вывод сведений о кафедрах по указанному диапазону аудиторий" << endl;
    cout << "9. Вывод кафедры с максимальным количеством преподавателей" << endl;
    cout << "10. Сохранение данных списка в бинарный файл" << endl;
    cout << "11. Извлечение данных из бинарного файла и помещение новых кафедр в список" << endl;
    cout << "0. Выход" << endl;
    do
    {

        cout << "\nВыберите пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printAll(head);
            break;
        case 2:
            addDepartmentToFront(head);
            break;
        case 3:
            addDepartmentToBack(head);
            break;
        case 4:
            addDepartmentAfter(head);
            break;
        case 5:
            addDepartmentBefore(head);
            break;
        case 6:
            deleteDepartment(head);
            break;
        case 7:
            printDepartmentsInCorpus(head);
            break;
        case 8:
            printDepartmentsInRoomRange(head);
            break;
        case 9:
            printDepartmentWithMaxTeachers(head);
            break;
        case 10:
            saveDepartmentsToFile(head);
            break;
        case 11:
            loadDepartmentsFromFile(head);
            break;
        case 0:
            cout << "\nВыход из программы." << endl;
            break;
        default:
            cout << "\nНеверный выбор. Повторите попытку." << endl;
        }
    } while (choice != 0);
}