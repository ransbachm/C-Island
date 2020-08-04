


#include <iostream> // cin, cout
#include <string> // strings
#include <array> // arrays

void eingabe(std::string &name, 
	unsigned &gebTag,
	unsigned &gebMonat,
	unsigned &gebJahr,
	long long &steuernummer,
	std::array<int, 12> &monatseinkommen) {

	using namespace std;
	cout << "Name: ";
	getline(std::cin, name);
	if(name.length() == 0) {
		cout << "Sie haben einen leeren Namen eingegeben.\n";
		exit(1);
	}

	cout << "Geb. Tag: "; cin >> gebTag;
	cout << "Geb. Monat "; cin >> gebMonat;
	cout << "Geb. Jahr: "; cin >> gebJahr;
	cout << "Steuernummer : "; cin >> steuernummer;

	for(int i=0; i<12; ++i) {
		cout << "Einkommen Monat " << i+1 << ": ";
		cin >> monatseinkommen[i];
	}
	cout << std::endl;
}

int main() {
	using namespace std;

	std::string name; // Initialisierung mir std. Konstruktor!
	unsigned tag = 0;
	unsigned monat = 0;
	unsigned jahr = 0;
	long long stNr = 0;
	std::array<int, 12> einkommen{};

	eingabe(name, tag, monat, jahr, stNr, einkommen);

	cout << name << " " << tag << " " << monat << " " << jahr << " " << stNr << " Einkommen : \n"; 
	for(int i=0; i<sizeof(einkommen) / sizeof(einkommen[0]); ++i) {
		cout << einkommen[i] << "\n";
	}
	cout << endl;
}
