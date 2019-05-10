/* 
 * File:   main.cpp
 * Author: Marina
 * 
 * Objectives:
 * 1.Реализовать функцию чтения файла
 * 2.Реализовать функцию записи в файл
 * 3.Реализовать функцию сортировки 
 * (сортировка пузырьком и вставками не использовать)
 * 4.Считывать, отсортировать и записать произвольный файл
 * 
 * Created on 5 мая 2019 г., 22:09
 */





//Импорт необходимых библиотек для дальнейшей реализации задачи
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Функция, предназначенная для чтения данных из файла
void user_read_file(const string &ref_path, vector<string> &s){
    ifstream file_input;    //создается ссылочная переменна для потока input
    file_input.exceptions(ifstream::badbit | ifstream::failbit);  
    
    //Блок обработки исключений при попытке открыть файл
    try{
        cout << "Попытка открыть файл " << ref_path << endl;
        
        file_input.open(ref_path);      //Ключевое слово, для открытия файла
        
        cout << "Файл успешно открыт!\n" << endl;
    }
    catch(const ifstream::failure & ex){
        cout << ex.what() << endl;      //Выводит в консоль информацию об исключении
        cout << ex.code() << endl;      //Выводит в консоль код возникшего исключения
        cout << "Ошибка при открытии файла!" << endl;
    }
    
    cout << "Чтение из файла...\n" << endl;
    
    //Цикл, считывает данные по строчно из файла и записывает их в строчный Вектор 
    //(т.к. изначально не известно количество строк в файле)
    while(!file_input.eof()){
        string tmp="";
        getline(file_input, tmp);
        s.push_back(tmp);
        cout<< tmp <<endl;
    }
    
    //Обязательная команда - закрытия файла после обработки
    file_input.close();
}

//Функция, предназначенная для записи данных в файл
void user_write_file(const string &ref_path, vector<string> &S){
    
    ofstream file_output;   //создается ссылочная переменна для потока input
    file_output.exceptions(ofstream::badbit | ofstream::failbit);
    
    //Блок обработки исключений при попытке открыть файл
    try{
        cout << "\n\nПопытка открыть файл " << ref_path << endl;
        file_output.open(ref_path);     //Ключевое слово, для открытия файла
        cout << "Файл успешно открыт!\n" << endl;
    }
    catch(const ofstream::failure & ex){
        cout << ex.what() << endl;      //Выводит в консоль информацию об исключении
        cout << ex.code() << endl;      //Выводит в консоль код возникшего исключения
        cout << "\n***Ошибка при записи файла!***\n" << endl;
    }
    
    //Особая форма цикла for - forEach предназначена для последовательного перебора
    //элементов строчного Вектора и записи их в файл.
    for(auto &c: S){
        file_output << c << endl;
    }
    cout << "Файл успешно записан!\n\n" << endl;
    
    //Обязательная команда - закрытия файла после обработки
    file_output.close();
}

//Функция сортировки Выбором
void user_SelectionSort_file(vector<string> &S){
    decltype(S.size()) n = S.size();
    string ss = "";
    int key;
    for (int i=0; i<n-1; i++){
        ss=S[i];
        key=i;
        for (int j=i+1; j<n; j++){
            if (S[j]<S[key]){
                key=j;
            }
        }
        if (key!=i){
            S[i]=S[key];
            S[key]=ss;
        }
    }
}


int main() {
    
    setlocale(LC_ALL, "ru");
    
    vector<string> line;        //Создается строчный Вектор для хранения массива строк.
                                //Использую Вектор - динамическую структуру данных,
                                //т.к. заранее не известно количество строк в файле
    
    //Создаю путь чтения и записи файлов.
    const string path_to_read = "Input.txt";
    const string path_to_write = "Output.txt";
    
    
    
    user_read_file(path_to_read, line);
    
    //Т.к. в задаче было условие НЕ использовать сортировку Пузырьком и Вставками,
    //Выбор остается на сортировке Выбором.
    //Сложность алгоритма не изменилась. О(n^2)
    user_SelectionSort_file(line);
    user_write_file(path_to_write, line);
   
    return 0;
}

