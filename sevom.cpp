#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Heyvan{
    string name;
    int cage_number;
    int year_of_entry;
    bool is_rare;
    bool is_fed;
};

void add(vector<Heyvan> &heyvan, int teded_ghafas){
    Heyvan h;
    cin >> h.name >> h.cage_number >> h.year_of_entry >> h.is_rare;
    h.is_fed = false;
    bool vojod_heyvan = false;

    for(int i = 0; i < heyvan.size(); i++){
        if(heyvan.at(i).cage_number == h.cage_number)
            vojod_heyvan = true;
    }
    
    bool flag = false;

    if(h.name.length() < 2){
        cout << "Invalid name" << endl;
        flag = true;
    }

    if (vojod_heyvan) {  
        cout << "Another animal is kept in this cage" << endl; 
        flag = true;
    }

    if (0 >= h.cage_number || h.cage_number > teded_ghafas){
        cout << "This cage does not exist" << endl;
        flag = true;
    }

    if (!flag){
        heyvan.push_back(h);
        cout << "The animal named " << h.name << " was added successfully" << endl;
    }
}

void search(vector<Heyvan> heyvan){
    string halat;
    cin >> halat;
    bool flag = false;

    if(halat == "name"){
        string namee;
        cin >> namee;

        for(int i = 0; i < heyvan.size(); i++){
            if(heyvan.at(i).name == namee){
                cout << heyvan.at(i).name << ' ' << heyvan.at(i).cage_number << ' ' << heyvan.at(i).year_of_entry << ' ' << heyvan.at(i).is_rare << endl;
                flag = true;
            }
        }
    }
    if(halat == "cage_number"){
        int num;
        cin >> num;
        for(int i = 0; i < heyvan.size(); i++){
            if(heyvan.at(i).cage_number == num){
               cout << heyvan.at(i).name << ' ' << heyvan.at(i).cage_number << ' ' << heyvan.at(i).year_of_entry << ' ' << heyvan.at(i).is_rare << endl;
                flag = true;
            }
        }
    }

    if(!flag)
        cout<< "No animal was found" << endl;

}

void list(vector<Heyvan> heyvan) {
    if(heyvan.size() == 0)
        cout << "No animal was found" << endl;
    else{
        for(int i = 0; i < heyvan.size(); i++){
            cout << heyvan.at(i).name << ' ' << heyvan.at(i).cage_number << ' ' << heyvan.at(i).year_of_entry << ' ' << heyvan.at(i).is_rare << endl;

        }
    }

}

void deletee(vector<Heyvan> &heyvan){

    int shomare_ghafas;
    bool flag = false;
    cin >> shomare_ghafas;
    for(int i = 0; i < heyvan.size(); i++){
        if(heyvan.at(i).cage_number == shomare_ghafas)
        {
            
            cout << "The animal named " << heyvan.at(i).name << " was deleted successfully" << endl;
            heyvan.erase(heyvan.begin()+i);
            flag = true;
            break;
        }
    }

    if(!flag)
        cout << "No animal was found" << endl;
}

void edit(vector<Heyvan> &heyvan){
    int shomare_ghafas;
    string halat;
    bool flag = false;
    cin >> shomare_ghafas >> halat;
    for(int i = 0; i < heyvan.size(); i++){
        if(heyvan.at(i).cage_number == shomare_ghafas){
            flag = true;
            if(halat == "name"){
                string newname;
                cin >> newname;
                if(newname.length() < 2){
                    cout << "Invalid name" << endl;
                }
                else{
                    cout << "The animal named " << heyvan.at(i).name << " was edited successfully" << endl;
                    heyvan.at(i).name = newname;
                }     
            }

            if(halat == "year_of_entry"){
                int newyear;
                cin >> newyear;
                heyvan.at(i).year_of_entry = newyear;
                cout << "The animal named " << heyvan.at(i).name << " was edited successfully" << endl;
            }
            
            if(halat == "is_rare"){
                if(heyvan.at(i).is_rare == false){
                    heyvan.at(i).is_rare = true;
                }
                else{
                    heyvan.at(i).is_rare = false;
                }
                cout << "The animal named " << heyvan.at(i).name << " was edited successfully" << endl;
            }

            if(halat == "is_fed"){
                if(heyvan.at(i).is_fed == false){
                    heyvan.at(i).is_fed = true;
                }
                else{
                    heyvan.at(i).is_fed = false;
                }
                cout << "The animal named " << heyvan.at(i).name << " was edited successfully" << endl;
            }
        }

        
    }
    if(!flag)
           cout << "No animal was found" << endl;
}

bool sortt(Heyvan a, Heyvan b){
    if(a.name == b.name)
        return a.cage_number < b.cage_number;
    else
        return a.name < b.name;
}

bool soort(Heyvan *a, Heyvan *b){

    if((*a).is_rare == (*b).is_rare)
        return (*a).year_of_entry < (*b).year_of_entry;
    else
        return (*a).is_rare > (*b).is_rare;

}

void feed(vector<Heyvan> &heyvan){

    int tedad;
    cin >> tedad;
    vector<Heyvan*> to_feed;
    for(int i = 0; i < heyvan.size(); i++){
        if(heyvan.at(i).is_fed == false)
            to_feed.push_back(&heyvan.at(i));
        
    }

    sort(to_feed.begin(), to_feed.end(), soort);
    int tedad_ghazadadan;
    if(tedad < to_feed.size()) {
        tedad_ghazadadan = tedad;
    }
    else {
        tedad_ghazadadan = to_feed.size();
    }

    for(int i = 0; i < tedad_ghazadadan; i++)
    {
        (*to_feed.at(i)).is_fed = true;
        cout << "The animal named " << (*to_feed.at(i)).name << " was fed" << endl;
    }
}

void save(vector<Heyvan> heyvan)
{
    string namefile;
    cin >> namefile;
    ofstream miyo;
    miyo.open(namefile, ios::out | ios::trunc);
        miyo << heyvan.size() << endl;
    for(int i = 0; i < heyvan.size(); i++){
        miyo << heyvan.at(i).name << ' ' << heyvan.at(i).cage_number << ' ' << heyvan.at(i).year_of_entry << ' ' << heyvan.at(i).is_rare << ' ' << heyvan.at(i).is_fed << endl;
    }
    miyo.close();
    cout << "Animals were saved successfully" << endl;
}

void load(vector<Heyvan> &heyvan){

    string namefile;
    cin >> namefile;
    ifstream miyo;
    miyo.open(namefile, ios::in);
    if(miyo.is_open()){
        Heyvan h;
        int tedad;
        miyo >> tedad;
        for(int i = 0; i < tedad; i++)
        {
            miyo >> h.name >> h.cage_number >> h.year_of_entry >> h.is_rare >> h.is_fed;
            heyvan.push_back(h);
        } 
        miyo.close();
        cout << "Animals were loaded successfully" << endl;
    }
    else{
        cout << "The file does not exist" << endl;
    }
       
}


int main ()
{
    string Dastoor;
    int teded_ghafas;
    vector <Heyvan> heyvan;

    while (cin >> Dastoor){
        if(Dastoor == "SET"){
            cin >> teded_ghafas;
        }

        else if(Dastoor == "ADD"){
            add(heyvan, teded_ghafas);
        }

        else if(Dastoor == "SEARCH"){
            search(heyvan);
        }

        else if(Dastoor == "LIST"){
            list(heyvan);
        }

        else if(Dastoor == "DELETE"){
            deletee(heyvan);
        }

        else if(Dastoor == "EDIT"){
            edit(heyvan);
        }

        else if(Dastoor == "SORT"){
            sort(heyvan.begin(), heyvan.end(), sortt);
        }

        else if(Dastoor == "FEED"){
            feed(heyvan);
        }
        else if(Dastoor == "EXIT"){
            break;
        }
        else if(Dastoor == "SAVE"){
            save(heyvan);
        }
        else if(Dastoor == "LOAD"){
            load(heyvan);
        }

    }
    return 0;
}
