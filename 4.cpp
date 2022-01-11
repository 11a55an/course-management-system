#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void writeTitle(vector<string> v){
	ofstream titleFile;
	titleFile.open("courseTitle.txt");

	for(int i=0;i<v.size();++i){
		titleFile<<v[i]<<endl;
	}

	titleFile.close();
}

void writeCode(vector<string> v){
	ofstream codeFile;
	codeFile.open("courseCode.txt");

	for(int i=0;i<v.size();++i){
		codeFile<<v[i]<<endl;
	}

	codeFile.close();
}

void writeHours(vector<int> v){
	ofstream hoursFile;
	hoursFile.open("creditHours.txt");

	for(int i=0;i<v.size();++i){
		hoursFile<<v[i]<<endl;
	}

	hoursFile.close();
}

void traverse(vector <string> course1,vector <string> course2,vector <int> course3){
    cout<<"Which array would you like to traverse:\n1. Course Title\n2. Course Code\n3. Credit Hours"<<endl;
    int op;
    cin>>op;

    if (op==1){
        for(int i=0; i < course1.size(); i++){
            cout <<"courseTitle["<<i<<"] = "<< course1[i] << "\n";
        }
    }

    else if (op==2){
        for(int i=0; i < course2.size(); i++){
            cout <<"courseCode["<<i<<"] = "<< course2[i] << "\n";
        }
    }

    else if (op==3){
        for(int i=0; i < course3.size(); i++){
            cout <<"creditHours["<<i<<"] = "<< course3[i] << "\n";
        }
    }
}

void search(vector <string> course1,vector <string> course2, vector <int> course3){
    cout<<"Would you like to search using:\n1. Course Title\n2. Course Code\n3. Credit Hours"<<endl;
    int op;
    cin>>op;

    if (op==1){
        cout<<"Enter the item you want to search for"<<endl;
        string item;
        cin.ignore();
        getline(cin, item);
        int i;
        for(i=0; i < course1.size(); i++){
            if(course1[i] == item){
                cout << "Element found at index [" << i<<"]"<<endl;
                cout << "Course Title = "<<course1[i]<<endl;
                cout << "Course Code = "<<course2[i]<<endl;
                cout << "Credit Hours = "<<course3[i]<<endl;
                break;
            }
        }
        if(i == course1.size()){
            cout  << "Element Not Present in Input Array\n";
        }
    }

    else if (op==2){
        cout<<"Enter the item you want to search for"<<endl;
        string item;
        cin.ignore();
        getline(cin, item);
        int i;
        for(i=0; i < course2.size(); i++){
            if(course2[i] == item){
                cout << "Element found at index [" << i<<"]"<<endl;
                cout << "Course Title = "<<course1[i]<<endl;
                cout << "Course Code = "<<course2[i]<<endl;
                cout << "Credit Hours = "<<course3[i]<<endl;
                break;
            }
        }
        if(i == course2.size()){
            cout  << "Element Not Present in Input Array\n";
        }
    }

    else if (op==3){
        cout<<"Enter the item you want to search for"<<endl;
        int item;
        cin>>item;
        int i;
        for(i=0; i < course3.size(); i++){
            if(course3[i] == item){
                break;
            }
        }

        if (i != course3.size()){
            for(int j=0; j < course3.size(); j++){
                if(course3[j] == item){
                    cout << "Element found at index [" << j<<"]"<<endl;
                    cout << "Course Title = "<<course1[j]<<endl;
                    cout << "Course Code = "<<course2[j]<<endl;
                    cout << "Credit Hours = "<<course3[j]<<"\n\n";
                }
            }
        }

        else if(i == course3.size()){
            cout  << "Element Not Present in Input Array\n";
        }
    }
}

void Update(vector <string> course1,vector <string> course2, vector <int> course3){
    cout<<"Which array would you like to update:\n1. Course Title\n2. Course Code\n3. Credit Hours"<<endl;
    int op;
    cin>>op;
    if (op==1){
        cout<<"Enter the index of item you want to update:\n";
        int pos;
        cin>>pos;
        cout<<"Enter the value of the updated element:"<<endl;
        string item;
        cin.ignore();
        getline(cin, item);
        course1[pos]=item;
        writeTitle(course1);     
    }

    else if (op==2){
        cout<<"Enter the index of item you want to update:\n";
        int pos;
        cin>>pos;
        cout<<"Enter the value of the updated element:"<<endl;
        string item;
        cin.ignore();
        getline(cin, item);
        course2[pos]=item;
        writeCode(course2);        
    }

    else if (op==3){
        cout<<"Enter the index of item you want to update:\n";
        int pos;
        cin>>pos;
        cout<<"Enter the value of the updated element:"<<endl;
        int item;
        cin>>item;
        course3[pos]=item;
        writeHours(course3);          
    }

}

void Insert(vector <string> course1,vector <string> course2, vector <int> course3,string title,string code){
   cout<<"Would you like to insert the element:\n1.Start of Array\n2.End of Array\n";
    int option;
    cin>>option;
    cout<<"Enter the Course Title of the new element you would like to insert:"<<endl;
    cin.ignore();
    getline(cin, title);
    cout<<"Enter the Course Code of the new element you would like to insert:"<<endl;
    getline(cin, code);
    cout<<"Enter the Credit Hours of the new element you would like to insert:"<<endl;
    int hours;
    cin>>hours;
    vector<string>::iterator it1;
    vector<string>::iterator it2;
    vector<int>::iterator it3;
    vector<string>::iterator it;

    if (option==1){
        auto it1 = course1.insert(course1.begin(), title);
        auto it2 = course2.insert(course2.begin(), code);
        auto it3 = course3.insert(course3.begin(), hours);
        cout<<"Insertion Done successfully";
    }

    else if (option==2){
        auto it1 = course1.insert(course1.end(), title);
        auto it2 = course2.insert(course2.end(), code);
        auto it3 = course3.insert(course3.end(), hours);
        cout<<"Insertion Done successfully";
    }

    writeTitle(course1);
    writeCode(course2);
    writeHours(course3);

}

void Delete(vector <string> course1,vector <string> course2, vector <int> course3){
    cout<<"Would you like to delete an element (Title+Code+CreditHour) at:\n1.Start of Array\n2.End of Array\n";
    int option,pos;
    cin>>option;
    std::vector<string>::iterator it1;
    std::vector<string>::iterator it2;
    std::vector<int>::iterator it3;
    if (option==1){
        auto it1 = course1.erase(course1.begin());
        auto it2 = course2.erase(course2.begin());
        auto it3 = course3.erase(course3.begin());
        cout<<"Deletion Done successfully";
    }

    else if (option==2){
        auto it1 = course1.erase(course1.end());
        auto it2 = course2.erase(course2.end());
        auto it3 = course3.erase(course3.end());
        cout<<"Deletion Done successfully";
    }
    
    writeTitle(course1);
    writeCode(course2);
    writeHours(course3);

}

int main(){
    ifstream titleFile("courseTitle.txt");
    ifstream codeFile("courseCode.txt");
    ifstream creditFile("creditHours.txt");

    if(!titleFile){
        cout<<"Error opening file courseTitle.txt"<<endl;
        system("pause");
        return -1;
    }

    if(!codeFile){
        cout<<"Error opening file courseTitle.txt"<<endl;
        system("pause");
        return -1;
    }

    if(!creditFile){
        cout<<"Error opening file courseTitle.txt"<<endl;
        system("pause");
        return -1;
    }

    string titleString;
    string codeString;
    string creditString;        
    vector <string> courseTitle;
    
    while (getline(titleFile, titleString)){
        courseTitle.push_back(titleString);
    }

    vector <string> courseCode;
    
    while (getline(codeFile, codeString)){
        courseCode.push_back(codeString);
    }

    vector <int> creditHours;
    
    while (getline(creditFile, creditString)){
        creditHours.push_back(stoi(creditString));
    }

    string title,code;
    int choice=-1;
	choice = -1;

	while (choice!=6) {
        system("CLS");
        cout<<"=====================================================\n";
	    cout<<"Course Management System\n";
	    cout<<"=====================================================\n";      
        cout<<"Enter the operation of your choice [1-6]:"<<endl;
        cout<<"1. Traverse\n2. Search\n3. Update\n4. Insert\n5. Delete\n6. Exit"<<endl;
        cin>>choice;
        switch (choice){
            case 1:
                traverse(courseTitle,courseCode,creditHours);
            break;

            case 2:
                search(courseTitle,courseCode,creditHours);
            break;

            case 3:
                Update(courseTitle,courseCode,creditHours);
            break;

            case 4:
                Insert(courseTitle,courseCode,creditHours,title,code);
            break;

            case 5:
                Delete(courseTitle,courseCode,creditHours);
            break;

            case 6:
            break;

            default:
                cout<<"You entered an invalid operator."<<endl;
            break;
        }
        system("PAUSE");
    }
    titleFile.close();
    codeFile.close();
    creditFile.close();
}