#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
public:
    string nama;
    string nim;
    float nilai[4]; // [0] Alpro, [1] Matdis, [2] Pweb, [3] Alin
    float nilaiAkhir = 0;
    char nilaiHuruf;
    string status;

    void input(int index) {
        cout << "| Masukkan Nama Mahasiswa ke- " << index + 1 << ": ";
        cin >> nama;
        cout << "| Masukkan NIM " << nama << ": ";
        cin >> nim;
        cout << "| " << endl;
        cout << "| Input Nilai Alpro " << nama << " : ";
        cin >> nilai[0];
        cout << "| Input Nilai Matdis " << nama << " : ";
        cin >> nilai[1];
        cout << "| Input Nilai Pweb " << nama << " : ";
        cin >> nilai[2];
        cout << "| Input Nilai Alin " << nama << " : ";
        cin >> nilai[3];
        cout << "+==============================================+\n";

        nilaiAkhir = (nilai[0] + nilai[1] + nilai[2] + nilai[3]) / 4;

        if (nilaiAkhir >= 85) {
            nilaiHuruf = 'A';
            status = "LULUS";
        } else if (nilaiAkhir >= 75) {
            nilaiHuruf = 'B';
            status = "LULUS";
        } else if (nilaiAkhir >= 60) {
            nilaiHuruf = 'C';
            status = "TIDAK LULUS";
        } else {
            nilaiHuruf = 'D';
            status = "TIDAK LULUS";
        }
    }

    void tampilkan(int index) {
        cout << "| Nama                  : " << nama << endl;
        cout << "| NIM                   : " << nim << endl;
        cout << "| Nilai Akhir Mahasiswa : " << nilaiAkhir << endl;
        cout << "| Huruf                 : " << nilaiHuruf << endl;
        cout << "| Kelulusan             : " << status << endl;
        cout << "+==============================================+\n";
    }
};

int main() {
    int jumlah, pilihan;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    Mahasiswa mhs[jumlah];
    bool sudahInput = false;

    do {
    	cout << endl;
        cout << "+================================+\n";
        cout << "|             MENU               |\n";
        cout << "+================================+\n";
        cout << "| 1. Input Nilai                 |\n";
        cout << "| 2. Tampilkan Data Nilai        |\n";
        cout << "| 3. Keluar                      |\n";
        cout << "+================================+\n";
        cout << "| Masukkan Pilihan: ";
        cin >> pilihan;
        cout << "+================================+\n";

        switch(pilihan) {
            case 1:
            	cout << "\n+==============================================+\n";
        		cout << "|             INPUT NILAI MAHASISWA            |\n";
        		cout << "+==============================================+\n";
                for(int i = 0; i < jumlah; i++) {
                    mhs[i].input(i); 
                }
                cout << "|     NILAI MAHASISWA BERHASIL DIINPUT         |\n";
        		cout << "+==============================================+\n";
                sudahInput = true;
                break;

            case 2:
                if (!sudahInput) {
                    cout << "\nBelum ada data yang diinputkan!\n";
                } else {
                	cout << "\n+==============================================+\n";
        			cout << "|              DATA NILAI MAHASISWA            |\n";
        			cout << "+==============================================+\n";
        			float totalNilai = 0;
					for(int i = 0; i < jumlah; i++) {
   						 mhs[i].tampilkan(i);
    					totalNilai += mhs[i].nilaiAkhir;
					}
					float rataRata = totalNilai / jumlah;
					
					cout << "+==============================================+\n";
					cout << "| Jumlah Mahasiswa          : " << jumlah << endl;
					cout << "| Total Nilai Mahasiswa     : " << totalNilai << endl;
					cout << "| Rata-rata nilai Mahasiswa : " << rataRata << endl;
					cout << "+==============================================+\n";
				}
				break;

            case 3:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan salah!\n";
        }
    } while (pilihan != 3);

    return 0;
}

