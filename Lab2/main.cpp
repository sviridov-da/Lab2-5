/*
Результатом должна быть консольная программа с текстовым меню. Программа
должна содержать шаблонный класс для управления данными согласно заданию.
Для хранения данных необходимо выбрать оптимальный с точки зрения задания
контейнер.
1. Предусмотреть операции добавления, изменения и удаления элемента
контейнера.
2. Реализовать ввод и вывод элементов контейнера с использованием потоковых
итераторов на экран и в файл.
3. Реализовать операции поиска по заданным критериям и выборки подмножества
элементов по заданным критериям. Реализовать поиск в двух вариантах: линейный
поиск и двоичный поиск на отсортированном контейнере.
4. Предусмотреть вывод подмножества выборки на экран и в файл.


Вариант 5. Модель компьютера характеризуется кодом и названием марки компьютера, типом
процессора, частотой работы процессора, объемом оперативной памяти, объемом
жесткого диска, объемом памяти видеокарты, стоимостью компьютера и
количеством экземпляров. Поиск по типу процессора, объему ОЗУ, памяти
видеокарты и объему жесткого диска.
*/
#include <iostream>
#include "DataStorage.h"
#include "computer_model.h"
#include "search_prop.h"



void save_storage_to_file(data_storage<computer_model>& storage)
{
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    ofstream output;
    output.open(file_name);
    if (output.is_open())
    {
        output << storage;
        cout << "Succes!\n";
    }
    else
        cout << "Saving failed\n";
}

void get_data_from_file(data_storage<computer_model>& storage)
{
    string file_name;
    cout << "Enter file name: ";
    cin >> file_name;
    ifstream input;
    input.open(file_name);
    if (input.is_open())
    {
        input >> storage;
        cout << "Succes!\n";
    }
    else
        cout << "Reading failed\n";
}

void work_with_element(data_storage<computer_model>& storage, list<computer_model>::iterator current)
{
    cout << "1 - change element\n";
    cout << "2 - delete element\n";
    char input;
    cin >> input;
    if (input == '1')
        storage.Change(current);
    else if (input == '2')
        storage.Delete(current);
    else
        cout << "Undefined command\n";
}

void search_element(data_storage<computer_model>& storage)
{
    search_prop properties;
    cout << "Enter search properties\n";
    cin >> properties;
    computer_model computer(0, "", properties.processor_type, properties.ram_size,
        properties.hard_disk_space, properties.video_card_memory, 0, 0);
    cout << "Choose search type:\n1 - linear\n2 - binary";
    char search_type;
    cin >> search_type;
    list<computer_model>::iterator current;
    if(search_type == '1')
        current = storage.search(computer, "lin");
    else
        current = storage.search(computer, "bin");
    if (current != storage.get_end())
        work_with_element(storage, current);
    else
        cout << "Element not found\n";
    

}

void work_with_subset(data_storage<computer_model>& subset)
{
    cout << "***Subset***\n";
    cout << subset;
    cout << "\nSave subset to file?\n1-yes\nother - no\n";
    char input;
    cin >> input;
    if (input != '1')
        return;
    string file_name;
    cout << "Enter file_name: ";
    cin >> file_name;
    ofstream os;
    os.open(file_name);
    if (os.is_open())
    {
        os << subset;
        os.close();
        cout << "Succes!\n";
    }
    else
        cout << "Saving failed\n";
}

void get_subset_by_processor_type(data_storage<computer_model>& storage, string processor_type)
{
    data_storage<computer_model> subset;
    for (list<computer_model>::iterator current = storage.get_begin(); current != storage.get_end(); current++)
        if (current->processor_type == processor_type) subset.Add(*current);
    work_with_subset(subset);
}

void get_subset_by_ram_size(data_storage<computer_model>& storage, int ram_size)
{
    data_storage<computer_model> subset;
    for (list<computer_model>::iterator current = storage.get_begin(); current != storage.get_end(); current++)
        if (current->ram_size == ram_size) subset.Add(*current);
    work_with_subset(subset);
}

void get_subset_by_video_card_memory(data_storage<computer_model>& storage, int video_card_memory)
{
    data_storage<computer_model> subset;
    for (list<computer_model>::iterator current = storage.get_begin(); current != storage.get_end(); current++)
        if (current->video_card_memory == video_card_memory) subset.Add(*current);
    work_with_subset(subset);
}

void get_subset_by_hard_disk_space(data_storage<computer_model>& storage, int hard_disk_space)
{
    data_storage<computer_model> subset;
    for (list<computer_model>::iterator current = storage.get_begin(); current != storage.get_end(); current++)
        if (current->hard_disk_space == hard_disk_space) subset.Add(*current);
    work_with_subset(subset);
}

void get_subset(data_storage<computer_model>& storage)
{
    data_storage<computer_model> subset;
    cout << "Choose criterion\n";
    cout << "1 - processor type\n";
    cout << "2 - RAM size\n";
    cout << "3 - Videocard memory\n";
    cout << "4 - Hard disk space\n";
    char input;
    string string_value;
    int int_value;
    cin >> input;
    switch (input)
    {
    case '1':
        cout << "Enter processor type: ";
        cin >> string_value;
        get_subset_by_processor_type(storage, string_value);
        break;
    case '2':
        cout << "Enter ram_size: ";
        cin >> int_value;
        get_subset_by_ram_size(storage, int_value);
        break;
    case '3':
        cout << "Enter vidoe card memory: ";
        cin >> int_value;
        get_subset_by_video_card_memory(storage, int_value);
        break;
    case '4':
        cout << "Enter hard disk space: ";
        cin >> int_value;
        get_subset_by_hard_disk_space(storage, int_value);
        break;
    }
    /*data_storage<computer_model> subset;
    for(list<computer_model>::iterator current = storage.get_begin(); current!=storage.get_end(); current++)*/

}

int main_menu(data_storage<computer_model> &storage)
{
    cout << "1 - print data\n";
    cout << "2 - save data to file\n";
    cout << "3 - add element from keyboard\n";
    cout << "4 - add elements from file (example file \"test.txt\")\n";
    cout << "5 - search element\n";
    cout << "6 - get subset\n";
    cout << "0 - exit\n";
    char input;
    cin >> input;
    switch (input)
    {
    case '1':
        cout << storage;
        cout << "Succes\n";
        return 1;
    case '2':
        save_storage_to_file(storage);
        return 2;
    case '3':
        cin >> storage;
        return 3;
    case '4':
        get_data_from_file(storage);
        return 4;
    case '5':
        search_element(storage);
        return 5;
    case '6':
        get_subset(storage);
        return 6;
    case '0':
        return 0;
    default:
        cout << "Undefined command";
        return -1;
    }
}

int main()
{
    data_storage<computer_model> storage;
    while (main_menu(storage) != 0) {}
    return 0;
}
