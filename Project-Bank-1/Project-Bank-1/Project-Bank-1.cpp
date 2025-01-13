#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;
enum Menu { ClientList = 1, NewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transaction = 6 ,Exit = 7 };
enum MenuForTransaction{ Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4 };
void ShowMenu();
void TransactionMenu();
struct stClient{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    int AccountBalance = 0;
    bool MarkForDelete = false;
};
short ReadClientChoice() {
    short choice;
    cin >> choice;
    return choice;
}
void PrintClientCard(stClient Clinet)
{
    cout << "\n\nThe following are the client Details : \n\n";
    cout << "Account Number : " << Clinet.AccountNumber << endl;
    cout << "PinCode : " << Clinet.PinCode << endl;
    cout << "Name : " << Clinet.Name << endl;
    cout << "Phone : " << Clinet.Phone << endl;
    cout << "Account Balance : " << Clinet.AccountBalance << endl;
}
void PrintClientRecord(stClient Client){
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(30) << Client.Name;
    cout << "| " << left << setw(12) << Client.Phone;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}
vector <string> SplitString(string S1,string Delim="#//#") {
    vector <string> vString;
    string sWord;
    short pos = 0;
    while ((pos=S1.find(Delim)) != string::npos) {
        sWord = S1.substr(0, pos);
        if (!sWord.empty()) {
            vString.push_back(sWord);
        }
        S1.erase(0,pos+Delim.length());
    }
    if (!S1.empty()) {
        vString.push_back(S1);
    }
    return vString;
}
stClient ConvertLineToRecord(string S1) {
    stClient Client;
  
    vector <string> vString;
    vString= SplitString(S1);
    if (vString.size() >= 5) {  // Ensure there are enough elements
        Client.AccountNumber = vString[0];
        Client.PinCode = vString[1];
        Client.Name = vString[2];
        Client.Phone = vString[3];
        Client.AccountBalance = stoi(vString[4]);  // Convert string to integer
    }
    else {
        // Handle error: Log or throw an exception if the line is malformed
        cout << "Error: Malformed client record in file." << endl;
    }

    return Client;
}
vector <stClient> LoadClientsDataFromFile() {
    vector <stClient> vClients;
    stClient Client;
    fstream File;
    File.open("Clients.txt", ios::in);
    if (File.is_open()) {
        string Line;
        while (getline(File, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        File.close();
    }
  
    return vClients;
   }
void PrintAllClientrecord(vector <stClient> vClients) {
 
    cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ") Client(s).  ";
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code ";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(12) << "Balance ";
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;
    for (stClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;

}
stClient ReadNewClient(const string & AccountNumber) {
        stClient Client;
        Client.AccountNumber = AccountNumber;  // Set the AccountNumber
        cout << "Enter PinCode ? ";
        getline(cin >> ws, Client.PinCode);
        cout << "Enter Name ? ";
        getline(cin, Client.Name);
        cout << "Enter Phone ? ";
        getline(cin, Client.Phone);
        cout << "Enter Account Balance ? ";
        cin >> Client.AccountBalance;
        cin.ignore();
        return Client;
    }
string ConvertRecordToLine(stClient Client,string Delim="#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Delim;
    stClientRecord += Client.PinCode + Delim;
    stClientRecord += Client.Name + Delim;
    stClientRecord += Client.Phone + Delim;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber ? ";
    cin >> AccountNumber;
    return AccountNumber;
}
void AddDataLineToFile(string strDataLine)
{   fstream MyFile;
    MyFile.open("Clients.txt", ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << strDataLine << endl;
        MyFile.close();
    }
}
void AddNewClient()
{
    vector <stClient> vClients=LoadClientsDataFromFile();
    stClient Client;
    bool IsDuplicated;
    do {
        IsDuplicated = false;
        Client.AccountNumber = ReadClientAccountNumber();
        for (stClient &client : vClients) {
            if (client.AccountNumber == Client.AccountNumber) {
                cout << "Client with " << Client.AccountNumber << " already exists, Enter another Account Number ?  ";
                IsDuplicated = true;
                break;
            }
        }
    } while (IsDuplicated);
    Client = ReadNewClient(Client.AccountNumber);
    string clientRecord = ConvertRecordToLine(Client,"#//#");
    AddDataLineToFile(clientRecord);
}
void AddClients()
{   
    char AddMore = 'Y';
    do
    {
        cout << "Adding New Client : \n\n";
        AddNewClient();
        cout << "\nClient Added Successfully , do you want to add more clients ? ";
       cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}
vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClient;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stClient Clinet;
        while (getline(MyFile, Line))
        {
            Clinet = ConvertLineToRecord(Line);
            vClient.push_back(Clinet);
        }
        MyFile.close();
    }
    return vClient;
}
bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients,stClient& Client){
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>&vClients)
{
    for (stClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
vector <stClient> SaveClientsDataToFile(vector <stClient>vClients){
    fstream MyFile;
    MyFile.open("Clients.txt", ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>&vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete client ? n/y ?";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(vClients);
            vClients = LoadClientsDataFromFile();
            cout << "\n\n Client Deleted Successfully. \n";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
            return false;
    }
}
stClient UpdateClientRecord(string AccountNumber){
    stClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "Enter PinCode ? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name ? ";
    getline(cin, Client.Name);
    cout << "Enter Phone ? ";
    getline(cin, Client.Phone);
    cout << "Enter Account Balance ? ";
    cin >> Client.AccountBalance;
    return Client;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>&vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {   
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want Update client ? n/y ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = UpdateClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(vClients);
            vClients = LoadClientsDataFromFile();
            cout << "\n\n Client Updated  Successfully. \n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
            return false;
    }
}
void AddingNewClient() {
    system("cls");
    cout << "----------------------------\n";
    cout << "  Add New Clients Screen  \n";
    cout << "----------------------------\n";
    AddClients();    
}
void PrintClientTransactionRecord(stClient Client) {
    cout << "| " << left << setw(20) << Client.AccountNumber;
    
    cout << "| " << left << setw(40) << Client.Name;

    cout << "| " << left << setw(30) << Client.AccountBalance;

}
void GoBackToTransactionMenu() {
    system("cls");
    TransactionMenu();
}
void PrintAllClientTransactionRecord(vector <stClient> vClients) {
    int TotalBalances = 0;

    cout << "\n\t\t\t\t\t Client List (" << vClients.size() << ") Client(s).  ";
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;
    cout << "| " << left << setw(20) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(30) << "Balance ";
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;
    for (stClient Client : vClients)
    {
        PrintClientTransactionRecord(Client);
        cout << endl;
        TotalBalances +=Client.AccountBalance;
    }
    cout << "\n---------------------------------------------------------";
    cout << "-------------------------------------------\n" << endl;
    cout << "Total Balances = " << TotalBalances<<endl;
    cout << "Press any key to go bakc to menu ..";
    system("pause");
    GoBackToTransactionMenu();

}
void DeletingClient() {
    system("cls");
    cout << "----------------------------\n";
    cout << "  Delet Client  Screen \n";
    cout << "----------------------------\n";
    vector <stClient> vClients = LoadClientsDataFromFile("Clients.txt");
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}
void UpdatingClient() {
    system("cls");
    cout << "----------------------------\n";
    cout << "  Update Client  Screen \n";
    cout << "----------------------------\n";
    vector <stClient> vClients = LoadClientsDataFromFile("Clients.txt");
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}
void FindingClient() {
    system("cls");
    cout << "----------------------------\n";
    cout << "  Find Client  Screen \n";
    cout << "----------------------------\n";
    vector <stClient> vClients = LoadClientsDataFromFile("Clients.txt");
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients,Client))
    {    
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
    }

}
int ReadAmount() {
    int amount;
    cin >> amount;
    return amount;
}
void AddDepositeAmount(int AccountBalance,stClient &C) {
    C.AccountBalance = C.AccountBalance + AccountBalance;
}
void DepositOperation() {
 
    stClient client;
    string AccountNumber;
    bool Find;
    vector <stClient> vClients = LoadClientsDataFromFile("Clients.txt");
    system("cls");
    cout << "----------------------------\n";
    cout << "  Deposit Client  Screen \n";
    cout << "----------------------------\n";
    do {
        Find = true;
        AccountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(AccountNumber, vClients, client)==false) {
            Find = false;
            cout << "Client with [" << AccountNumber << "] doesn not exist.\n";
            cout << "Please Enter an Account number";
        }
    } while (Find == false);
    PrintClientCard(client);
    cout << endl;
    cout << "Please Enter Deposite amount?";
    int amount = 0;
    amount = ReadAmount();
    char Confirm;
    cout << "Are you sure you want to perfom this transaction ? y/n ";
    cin >> Confirm;
    if (Confirm == 'y') {
        AddDepositeAmount(amount, client);
        for (stClient& C : vClients) {
            if (C.AccountNumber == AccountNumber) {
                C.AccountBalance = client.AccountBalance; // Update the balance in the vector
                break;
            }
        }
        SaveClientsDataToFile(vClients);
        vClients = LoadClientsDataFromFile("Clients.txt");
        GoBackToTransactionMenu();
    }
    else
        GoBackToTransactionMenu();



}
void WithdrawOperation() {
    stClient client;
    string AccountNumber;
    int amount = 0;
    bool CheckAmount;
    bool Find;
    char Confirm;
    vector <stClient> vClients = LoadClientsDataFromFile("Clients.txt");
    system("cls");
    cout << "----------------------------\n";
    cout << "      Withdraw Screen \n";
    cout << "----------------------------\n";
    do {
        Find = true;
        AccountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(AccountNumber, vClients, client) == false) {
            Find = false;
            cout << "Client with [" << AccountNumber << "] doesn not exist.\n";
            cout << "Please Enter an Account number";
        }
    } while (Find == false);
    PrintClientCard(client);
    cout << endl;
    cout << "Please Enter Withdraw amount?";
    do {
        CheckAmount = false;
        amount = ReadAmount();
        for (stClient& C : vClients) {
            if (C.AccountNumber == AccountNumber) {
                if (C.AccountBalance < amount) {
                    cout << "Amount Exceeds the balance, you can withdraw up to: " << C.AccountBalance << endl;
                    CheckAmount = true;
                    cout << "Please Enter another withdraw amount: ";
                    break;
                }
            }
        }
    } while (CheckAmount == true);
    cout << "Are you sure you want to perfom this transaction ? y/n ";
    cin >> Confirm;
    if (Confirm == 'y') {
        AddDepositeAmount((-amount), client);
        for (stClient& C : vClients) {
            if (C.AccountNumber == AccountNumber) {
                C.AccountBalance = client.AccountBalance;
                break;
            }
        }
        SaveClientsDataToFile(vClients);
        vClients = LoadClientsDataFromFile("Clients.txt");
        GoBackToTransactionMenu();
    }
    else {
        GoBackToTransactionMenu();
    }
}
void TotalBalances() {
    vector <stClient> vClients = LoadClientsDataFromFile();
    PrintAllClientTransactionRecord(vClients);
}
void ApplyTansactionClientChoice(MenuForTransaction choice) {
    system("cls");
    switch (choice) {
    case Deposit:
        DepositOperation();
        break;
    case Withdraw:
        WithdrawOperation();
        break;
    case TotalBalance:
        TotalBalances();
        break;
    case MainMenu:
        ShowMenu();
        break;

    }

}
void TransactionMenu() {
short choice=0 ;
    cout << "===========================================================================\n";
    cout << "\t\t Transaction Menue Screen\t\t\n";
    cout << "===========================================================================\n";
    cout << "[1] Deposit.\n";
    cout << "[2] Withdraw.\n";
    cout << "[3] Total Balances.\n";
    cout << "[4] Main Menu.\n";
    cout << "===========================================================================\n";
    cout << "Choose what do you want to do? [1 to 4] ?";
    choice = ReadClientChoice();
    ApplyTansactionClientChoice((MenuForTransaction)choice);


}
void GoBackToMenu() {
    cout << "Press any key to go bakc to menu ..";
    system("pause");
    system("cls");
    ShowMenu();

}
void ApplyClientChoice(short ClientChoice) {
    Menu choice = Menu(ClientChoice);
    system("cls");
    switch (choice) {
        
    case ClientList:
        PrintAllClientrecord(LoadClientsDataFromFile());
        GoBackToMenu();
        break;
    case NewClient:
        AddingNewClient();
        GoBackToMenu();
        break;
    case DeleteClient:
        DeletingClient();
        GoBackToMenu();
        break;
    case UpdateClient:
        UpdatingClient();
        GoBackToMenu();
        break;
    case FindClient:
        FindingClient();
        GoBackToMenu();
        break;
    case Transaction:
        TransactionMenu();
        break;
    case Exit:
            cout << "------------------------------------------\n";
            cout << "\t\tProgram Ends :)\n";
            cout << "------------------------------------------\n";
            GoBackToMenu();
            break;
        
    }

}
void ShowMenu() {
    short choice = 0;
    cout << "===========================================================================\n";
    cout << "\t\t Main Menue Screen\t\t\n";
    cout << "===========================================================================\n";
    cout << "[1] Show Client List.\n";
    cout << "[2] Add New Client.\n";
    cout << "[3] Delete Client.\n";
    cout << "[4] Update Client Info.\n";
    cout << "[5] Find Client.\n";
    cout << "[6] Transactions\n";
    cout << "[7] Exit.\n";
    cout << "===========================================================================\n";
    cout << "Choose what do you want to do? [1 to 6]? ";
    choice = ReadClientChoice();
    ApplyClientChoice(choice);
}

int main()
{
    ShowMenu();
    system("pause>0");
    return 0;
}
