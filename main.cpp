#include<iostream>
#include<iomanip>
#include<windows.h> // sleep
#include<conio.h> // khib
#include<string>
#include<ctime> // rand
#include<cstdlib> // exit


using namespace std;
const int meniu_eilute = 3;
const int meniu_stulpelis = 16;
class Base{
    virtual void pradedame_zaidima()=0;
};
class Laivu_musis: public Base
{
private:

    char zaidejo_atakos_radaras[11][13] =
    {
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
    };

    char zaidejo_lenta[11][13] =
    {
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
    };

    char kompiuterio_lenta[11][13] =
    {
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
        {'#','-','-','-','-','-','-','-','-','-','-','#'},
    };



    char meniu[meniu_eilute][meniu_stulpelis] =
    {
        {' ','N','a','u','j','a','s',' ','z','a','i','d','i','m','a','s'},
        {' ',' ','I','n','s','t','r','u','k','c','i','j','o','s',' ',' '},
        {' ',' ',' ',' ',' ','I','s','e','i','t','i',' ',' ',' ',' ',' '},
    };

    char hv[10];
    char zaidejo_laivu_kordinates[10];
    char zaidejo_puolimo_kordinates[10];
    int a=65,b=65;
    int kompiuterio_laivu_vietos_ant_lentos = 10;
    int zaidejo_laivu_vietos_ant_lentos = 10;
    int rodykle_eilute=0 , rodykle_stulpelis=0 ;
    int vienviecio_dydis = 1, zaidejo_vienviecio_dydis = 1;
    int dviviecio_dydis = 2, zaidejo_dviviecio_dydis = 2;
    int triviecio_dydis = 3, zaidejo_triviecio_dydis = 3;
    int keturviecio_dydis = 4, zaidejo_keturviecio_dydis = 4;
    int eilute, stulpelis;
    int eilutes_puolimas, stulpelio_puolimas;
    int kompiuterio_eilute, kompiuterio_stulpelis;
    int kompiuterio_eilutes_puolimas, kompiuterio_stulpelio_puolimas;
    int kompiuterio_hv;
    char meniu_pasirinkti;
    char aukstyn_zemyn;
    char pirmoji_kompiuterio_kordinate;
    int laivu_skaicius ;
    int kompiuterio_laivai ;
    bool teisinga_laivo_padetis;
    bool teisinga_kompiuterio_padetis;
    bool teisingos_puolimo_kordinates;
    bool teisingos_kompiuterio_puolimo_kordinates;
    bool pataike = false;
    bool vienvietis_pataikytas = false;
    bool dvivietis_pataikytas = false;
    bool trivietis_pataikytas = false;
    bool keturvietis_pataikytas = false;

    string vardas;


public:
    Laivu_musis(int x, int y){
    laivu_skaicius = x;
    kompiuterio_laivai = y;
    }
    Laivu_musis(bool r, bool r1, bool r2, bool r3){
    vienvietis_pataikytas = r;
    dvivietis_pataikytas = r1;
    trivietis_pataikytas = r2;
    keturvietis_pataikytas = r3;


    }


    void atspausdinti_meniu()
    {
        system ("cls");
        for (int i = 0; i < meniu_eilute; i++)
        {
            cout << setw(56);
            for (int j = 0; j < meniu_stulpelis; j++)
            {
                if (i == rodykle_eilute && j == rodykle_stulpelis)
                {
                    cout << (char)175; // >>
                }
                cout << meniu[i][j];
            }
            cout << endl;
        }
    }

    void zaidejas_pasirenka_meniu()
    {
        while (1)
        {
            if (kbhit())
            {
                meniu_pasirinkti = getch();
                if (rodykle_eilute == 0 && rodykle_stulpelis == 0 && meniu_pasirinkti == 13)
                {

                    Ivesti_varda();
                    operator++();
                    atspausdinti_radarus();
                    zaidejo_ivestos_kordinates();
                    pradedame_zaidima();
                    zaidejas_atakuoja();
                }
                else if (rodykle_eilute == 1 && rodykle_stulpelis == 0 && meniu_pasirinkti == 13)
                {

                    Instrukcijos();
                    if (meniu_pasirinkti == -32)
                    {

                        Instrukcijos();

                    }
                }

                else if (rodykle_eilute == 2 && rodykle_stulpelis == 0 && meniu_pasirinkti == 13)
                {
                    exit(0);
                }
                else if (meniu_pasirinkti == -32)
                {
                    aukstyn_zemyn = getch();
                    switch (aukstyn_zemyn)
                    {
                    case 72:
                        if (rodykle_eilute > 0)
                        {
                            rodykle_eilute--;
                        }
                        break;
                    case 80:
                        if (rodykle_eilute < meniu_eilute - 1)
                        {
                            rodykle_eilute++;
                        }
                        break;
                    }


                    atspausdinti_meniu();
                }
            }
        }
    }

    void Ivesti_varda()
    {
        system("CLS");
        for (int i = 0; i < 20; i++)
        {
            cout << endl;
        }
        cout << setw(72) << "Iveskite savo varda: ";
        getline(cin, vardas);
    }

    void laivu_skaiciai()
    {
        system("CLS");
        cout << setw(52) << "Kompiuterio laivu lentele" << (char)179 << " " << vardas << " laivu lentele" << endl;
        cout << endl;
        cout << setw(43)  << "Vienvieciu: " << vienviecio_dydis << setw(9) << (char)179 << setw(18) << "Vienvieciu: " << zaidejo_vienviecio_dydis <<  endl;
        cout << setw(43)  << "Dvivieciu: " << dviviecio_dydis << setw(9) << (char)179 << setw(18) << "Dvivieciu: " << zaidejo_dviviecio_dydis  <<  endl;
        cout << setw(43)  << "Trivieciu: " << triviecio_dydis << setw(9) << (char)179 << setw(18) << "Trivieciu: " << zaidejo_triviecio_dydis  <<  endl;
        cout << setw(43)  << "Keturvieciu: " << keturviecio_dydis << setw(9) << (char)179 << setw(18) << "Keturvieciu: " << zaidejo_keturviecio_dydis <<  endl;



    }

    void atspausdinti_radarus()
    {
        laivu_skaiciai();
        for (int i = 0; i < 5; i++)
        {
            cout << endl;
        }
        cout << setw(52) << "0 1 2 3 4 5 6 7 8 9" << setw(41) << "0 1 2 3 4 5 6 7 8 9" << endl;
        cout << setw(32) << (char)218;
        for (int j = 0; j < 21; j++) // virsus
        {
            cout << (char)196;
        }
        cout << (char)191 << setw(19) << (char)218;
        for (int n = 0; n < 21; n++)
        {
            cout << (char)196;
        }
        cout << (char)191 << endl;
        for (int k = 0; k < 10; k++)
        {
            cout << setw(30) << (char)a++ << " ";
            for (int l = 0; l < 12; l++)
            {
                if (zaidejo_lenta[k][l] == '-')
                {
                    cout << (char)248 << " ";
                }
                else if (zaidejo_lenta[k][l] == '#')
                {
                    cout << (char)179 << " ";
                }
                else if (zaidejo_lenta[k][l] == 'V')
                {
                    cout << (char)118 << " ";
                }
                else if (zaidejo_lenta[k][l] == 'D')
                {
                    cout << (char)68 << " ";
                }
                else if (zaidejo_lenta[k][l] == 'T')
                {
                    cout << (char)84 << " ";
                }
                else if (zaidejo_lenta[k][l] == 'K')
                {
                    cout << (char)75 << " ";
                }
                else if (zaidejo_lenta[k][l] == '!')
                {
                    cout << (char)33 << " ";
                }
                else if (zaidejo_lenta[k][l] == '$')
                {
                    cout << (char)237 << " ";
                }
            }
            cout << setw(17) << (char)b++;
            for (int m = 0; m < 12; m++)
            {
                if (zaidejo_atakos_radaras[k][m] == '-')
                {
                    cout << (char)248 << " ";
                }
                else if (zaidejo_atakos_radaras[k][m] == '#')
                {
                    cout << (char)179 << " ";
                }
                else if (zaidejo_atakos_radaras[k][m] == '!')
                {
                    cout << (char)33 << " ";
                }
                else if (zaidejo_atakos_radaras[k][m] == '$')
                {
                    cout << (char)237 << " ";
                }
            }
            cout << endl;
        }
        a = 65;
        b = 65;
        cout << setw(32) << (char)192; // apacia
        for (int o = 0; o < 21; o++)
        {
            cout << (char)196;
        }
        cout << (char)217 << setw(19) << (char)192;
        for (int p = 0; p < 21; p++)
        {
            cout << (char)196;
        }
        cout << (char)217 << endl << endl;
    }

    void zaidejo_ivestos_kordinates()
    {
        do
        {
            teisinga_laivo_padetis = true;
            if (laivu_skaicius == 0)
            {
                cout << setw(90) << "Iveskite kordinate savo vienvieciam laivui (1): ";
            }
            else if (laivu_skaicius == 1)
            {
                cout << setw(89) << "Iveskite kordinate savo dvieciam laivui (2): ";
            }
            else if (laivu_skaicius == 2)
            {
                cout << setw(88) << "Iveskite kordinate savo trivieciam laivui (3): ";
            }
            else if (laivu_skaicius == 3)
            {
                cout << setw(91) << "Iveskite kordinate savo keturvieciam laivui (4): ";
            }
            cin.getline(zaidejo_laivu_kordinates, 10, '\n');
            cout << endl << endl;
            ar_teisingos_kordinates();
            atspausdinti_radarus();
            if (teisinga_laivo_padetis == true)
            {
                laivu_skaicius++;
            }
        }
        while (!teisinga_laivo_padetis || laivu_skaicius < 4);
    }

    void ar_teisingos_kordinates()
    {

        if (zaidejo_laivu_kordinates[0] < 'a' || zaidejo_laivu_kordinates[0] > 'j' ||
                zaidejo_laivu_kordinates[1] < '0' || zaidejo_laivu_kordinates[1] > '9')
        {
            teisinga_laivo_padetis = false;
            atspausdinti_radarus();
            cout << setw(91) << "Neteisingos kordinates" << endl;
            cout << setw(98) << "Kordinates ivedame pagal pavyzdi, raide|skaicus = a3" << endl;
            Sleep(2000);
        }
        else
        {
            priskirti_reiksmes_eilutems_stulpeliams();
            patikrinimas_del_pozicijos();
        }
    }

    void patikrinimas_del_pozicijos()
    {
        if (zaidejo_lenta[eilute][stulpelis] == '-')
        {
            if (laivu_skaicius == 0)
            {
                zaidejo_lenta[eilute][stulpelis] = 'V';
            }
            else if (laivu_skaicius == 1)
            {
                zaidejo_lenta[eilute][stulpelis] = 'D';
            }
            else if (laivu_skaicius == 2)
            {
                zaidejo_lenta[eilute][stulpelis] = 'T';
            }
            else if (laivu_skaicius == 3)
            {
                zaidejo_lenta[eilute][stulpelis] = 'K';
            }
           if(laivu_skaicius>0) {horizontaliai_ar_vertikaliai();}
        }
        else
        {
            atspausdinti_radarus();
            cout << setw(92) << "Vieta uzimta" << endl << endl;
            Sleep(2000);
            teisinga_laivo_padetis = false;
        }
    }

    void horizontaliai_ar_vertikaliai()
    {

        atspausdinti_radarus();
        cout << setw(28) << zaidejo_laivu_kordinates[0] << zaidejo_laivu_kordinates[1] << " spauskite (h) kad pastatyti laiva horizontaliai (v) kad vertikaliai: ";
        cin.getline(hv, 10, '\n');
        if (hv[0] == 'h')
        {
            if (laivu_skaicius == 0)
            {
                zaidejo_lenta[eilute][stulpelis] = 'V';
            }
            else if (laivu_skaicius == 1 && zaidejo_lenta[eilute][stulpelis + 1] == '-')
            {
                zaidejo_lenta[eilute][stulpelis + 1] = 'D';

            }
            else if (laivu_skaicius == 2 && zaidejo_lenta[eilute][stulpelis + 1] == '-' && zaidejo_lenta[eilute][stulpelis + 2] == '-' )
            {
                zaidejo_lenta[eilute][stulpelis + 1] = 'T';
                zaidejo_lenta[eilute][stulpelis + 2] = 'T';

            }
            else if (laivu_skaicius == 3 && zaidejo_lenta[eilute][stulpelis + 1] == '-' && zaidejo_lenta[eilute][stulpelis + 2] == '-' &&  zaidejo_lenta[eilute][stulpelis + 3] == '-')
            {
                zaidejo_lenta[eilute][stulpelis + 1] = 'K';
                zaidejo_lenta[eilute][stulpelis + 2] = 'K';
                zaidejo_lenta[eilute][stulpelis + 3] = 'K';

            }
            else
            {
                atspausdinti_radarus();
                cout << setw(85) << "Per mazai vietos kad pastatyti horizontaliai" << endl << endl;
                Sleep(3000);
                zaidejo_lenta[eilute][stulpelis] = '-';
                teisinga_laivo_padetis = false;
            }
        }
        else if (hv[0] == 'v')
        {
            if (laivu_skaicius == 0)
            {
                zaidejo_lenta[eilute][stulpelis] = 'V';
            }
            else if (laivu_skaicius == 1 && zaidejo_lenta[eilute + 1][stulpelis] == '-')
            {
                zaidejo_lenta[eilute + 1][stulpelis] = 'D';

            }
            else if (laivu_skaicius == 2 && zaidejo_lenta[eilute + 1][stulpelis] == '-' && zaidejo_lenta[eilute + 2][stulpelis] == '-' )
            {
                zaidejo_lenta[eilute + 1][stulpelis] = 'T';
                zaidejo_lenta[eilute + 2][stulpelis] = 'T';

            }
            else if (laivu_skaicius == 3 && zaidejo_lenta[eilute + 1][stulpelis] == '-' && zaidejo_lenta[eilute + 2][stulpelis] == '-' &&  zaidejo_lenta[eilute + 3][stulpelis] == '-')
            {
                zaidejo_lenta[eilute + 1][stulpelis] = 'K';
                zaidejo_lenta[eilute + 2][stulpelis] = 'K';
                zaidejo_lenta[eilute + 3][stulpelis] = 'K';

            }
            else
            {
                atspausdinti_radarus();
                cout << setw(85) << "Per mazai vietos kad pastatyti vertikaliai" << endl << endl;
                Sleep(3000);
                zaidejo_lenta[eilute][stulpelis] = '-';
                teisinga_laivo_padetis = false;
            }
        }
        else
        {
            atspausdinti_radarus();
            cout << setw(105) << "prasau spausti 'h' , kad pastatyti horizontaliai 'v' , kad vertikaliai." << endl << endl;
            zaidejo_lenta[eilute][stulpelis] = '-';
            Sleep(5000);
            teisinga_laivo_padetis = false;
        }
    }

    void pradedame_zaidima()
    {

            system("CLS");

    }

    void operator++()
    {

        do
        {
            system("CLS");
            teisinga_kompiuterio_padetis = true;
            srand(time(0));
            kompiuterio_eilute = rand() % 11;
            kompiuterio_stulpelis = rand() % 11;
            kompiuterio_patikrinimas_del_teisngos_pozicijos();
            if (teisinga_kompiuterio_padetis == true)
            {
                kompiuterio_laivai++;
            }
        }
        while (kompiuterio_laivai < 4 || !teisinga_kompiuterio_padetis);

        system("CLS");

    }

    void kompiuterio_patikrinimas_del_teisngos_pozicijos()
    {
        if (kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] == '-')
        {
            if (kompiuterio_laivai == 0)
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = 'V';
            }
            else if (kompiuterio_laivai == 1)
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = 'D';
            }
            else if (kompiuterio_laivai == 2)
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = 'T';
            }
            else if (kompiuterio_laivai == 3)
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = 'K';
            }
            kompiuteris_pasirenka_vertikaliai_ar_horizontaliai();
        }
        else
        {
            teisinga_kompiuterio_padetis = false;
        }
    }


    void kompiuteris_pasirenka_vertikaliai_ar_horizontaliai()
    {
        kompiuterio_hv = 1 + rand() % 2;
        if (kompiuterio_hv == 1)
        {
            if (kompiuterio_laivai == 0 )
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis ] = 'V';

                 kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis ] = '$';
                  kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis+1] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                    kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';


            }
            else if (kompiuterio_laivai == 1 && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] == '-')
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] = 'D';

                kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis ] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                    kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';

                        kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +2] = '$';
                          kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +2] = '$';
                            kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis +2] = '$';


            }
            else if (kompiuterio_laivai == 2 && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] == '-' && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 2] == '-')
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] = 'T';
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 2] = 'T';

                kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis ] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                    kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';

                        kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +2] = '$';
                          kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +2] = '$';

                           kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis +3] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +3] = '$';
                             kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +3] = '$';





            }
            else if (kompiuterio_laivai == 3 && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] == '-' && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 2] == '-' && kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 3] == '-')
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 1] = 'K';
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 2] = 'K';
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis + 3] = 'K';

                 kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis ] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                    kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';

                        kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +2] = '$';
                          kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +2] = '$';


                            kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +3] = '$';
                             kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +3] = '$';

                              kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis +4] = '$';
                               kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +4] = '$';
                                kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +4] = '$';


            }
            else
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = '-';
                teisinga_kompiuterio_padetis = false;
            }
        }
        else if (kompiuterio_hv == 2)
        {
            if (kompiuterio_laivai == 0 )
            {
                kompiuterio_lenta[kompiuterio_eilute ][kompiuterio_stulpelis] = 'V';


                 kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis ] = '$';
                  kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis+1] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                    kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';
            }
            else if (kompiuterio_laivai == 1 && kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] == '-' )
            {
                kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] = 'D';

                 kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                  kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis+1] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';

                        kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis] = '$';
                          kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis +1] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis -1] = '$';


            }
            else if (kompiuterio_laivai == 2 && kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] == '-' && kompiuterio_lenta[kompiuterio_eilute + 2][kompiuterio_stulpelis] == '-')
            {
                kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] = 'T';
                kompiuterio_lenta[kompiuterio_eilute + 2][kompiuterio_stulpelis] = 'T';

               kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                  kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis+1] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';


                          kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis +1] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis -1] = '$';

                             kompiuterio_lenta[kompiuterio_eilute+3][kompiuterio_stulpelis] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+3][kompiuterio_stulpelis -1] = '$';
                             kompiuterio_lenta[kompiuterio_eilute+3][kompiuterio_stulpelis +1] = '$';




            }
            else if (kompiuterio_laivai == 3 && kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] == '-' && kompiuterio_lenta[kompiuterio_eilute + 2][kompiuterio_stulpelis] == '-' && kompiuterio_lenta[kompiuterio_eilute + 3][kompiuterio_stulpelis] == '-')
            {
                kompiuterio_lenta[kompiuterio_eilute + 1][kompiuterio_stulpelis] = 'K';
                kompiuterio_lenta[kompiuterio_eilute + 2][kompiuterio_stulpelis] = 'K';
                kompiuterio_lenta[kompiuterio_eilute + 3][kompiuterio_stulpelis] = 'K';

                 kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis ] = '$';
                  kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis+1] = '$';
                   kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis +1] = '$';
                     kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis -1] = '$';
                       kompiuterio_lenta[kompiuterio_eilute+1][kompiuterio_stulpelis -1] = '$';
                      kompiuterio_lenta[kompiuterio_eilute-1][kompiuterio_stulpelis +1] = '$';


                          kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis +1] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+2][kompiuterio_stulpelis -1] = '$';

                            kompiuterio_lenta[kompiuterio_eilute+3][kompiuterio_stulpelis -1] = '$';
                             kompiuterio_lenta[kompiuterio_eilute+3][kompiuterio_stulpelis +1] = '$';

                             kompiuterio_lenta[kompiuterio_eilute+4][kompiuterio_stulpelis] = '$';
                            kompiuterio_lenta[kompiuterio_eilute+4][kompiuterio_stulpelis -1] = '$';
                             kompiuterio_lenta[kompiuterio_eilute+4][kompiuterio_stulpelis +1] = '$';

            }
            else
            {
                kompiuterio_lenta[kompiuterio_eilute][kompiuterio_stulpelis] = '-';
                teisinga_kompiuterio_padetis = false;
            }
        }
        system("CLS");
    }

    void zaidejas_atakuoja()
    {
        do
        {
            teisingos_puolimo_kordinates = true;
            atspausdinti_radarus();
            cout << setw(76) << "iveskite atakos kordinates: ";
            cin.getline(zaidejo_puolimo_kordinates, 10, '\n');

            patikrinimas_del_teisingu_atakos_kordinaciu();
            if (kompiuterio_laivu_vietos_ant_lentos == 0)
            {
                for (int i = 0; i < 6; i++)
                {
                    system("CLS");
                    system("Color 4E");
                    for (int i = 0; i < 19; i++)
                    {
                        cout << endl;
                    }
                    Sleep(500);
                    cout << setw(60) << vardas << " ,JUS LAIMEJOTE!!!" << endl;
                    Sleep(500);


                }
       exit(0);
            }
            else if (teisingos_puolimo_kordinates == true)
            {
                Sleep(500);
                atspausdinti_radarus();
                kompiuteris_atakuoja();
            }
        }
        while (!teisingos_puolimo_kordinates || kompiuterio_laivu_vietos_ant_lentos > 0);
    }

    void patikrinimas_del_teisingu_atakos_kordinaciu()
    {
        if (zaidejo_puolimo_kordinates[0] < 'a' || zaidejo_puolimo_kordinates[0] > 'j' ||
                zaidejo_puolimo_kordinates[1] < '0' || zaidejo_puolimo_kordinates[1] > '9')
        {
            teisingos_puolimo_kordinates = false;
            system("CLS");
            atspausdinti_radarus();
            cout << setw(91) << "Neteisingos kordinates." << endl;
            cout << setw(98) << "Kordinates ivedame pagal pavyzdi, raide|skaicus = a3" << endl;
            Sleep(3000);
        }
        else
        {
            priskirti_atakos_reiksmes_eilutems_stulpeliams();
            zaidejas_atakuoja_lenta();
        }
    }

    void priskirti_reiksmes_eilutems_stulpeliams()
    {

        if (zaidejo_laivu_kordinates[0] == 'a')
        {
            eilute = 0;
        }
        else if (zaidejo_laivu_kordinates[0] == 'b')
        {
            eilute = 1;
        }
        else if (zaidejo_laivu_kordinates[0] == 'c')
        {
            eilute = 2;
        }
        else if (zaidejo_laivu_kordinates[0] == 'd')
        {
            eilute = 3;
        }
        else if (zaidejo_laivu_kordinates[0] == 'e')
        {
            eilute = 4;
        }
        else if (zaidejo_laivu_kordinates[0] == 'f')
        {
            eilute = 5;
        }
        else if (zaidejo_laivu_kordinates[0] == 'g')
        {
            eilute = 6;
        }
        else if (zaidejo_laivu_kordinates[0] == 'h')
        {
            eilute = 7;
        }
        else if (zaidejo_laivu_kordinates[0] == 'i')
        {
            eilute = 8;
        }
        else if (zaidejo_laivu_kordinates[0] == 'j')
        {
            eilute = 9;
        }

        if (zaidejo_laivu_kordinates[1] == '0')
        {
            stulpelis = 1;
        }
        else if (zaidejo_laivu_kordinates[1] == '1')
        {
            stulpelis = 2;
        }
        else if (zaidejo_laivu_kordinates[1] == '2')
        {
            stulpelis = 3;
        }
        else if (zaidejo_laivu_kordinates[1] == '3')
        {
            stulpelis = 4;
        }
        else if (zaidejo_laivu_kordinates[1] == '4')
        {
            stulpelis = 5;
        }
        else if (zaidejo_laivu_kordinates[1] == '5')
        {
            stulpelis = 6;
        }
        else if (zaidejo_laivu_kordinates[1] == '6')
        {
            stulpelis = 7;
        }
        else if (zaidejo_laivu_kordinates[1] == '7')
        {
            stulpelis = 8;
        }
        else if (zaidejo_laivu_kordinates[1] == '8')
        {
            stulpelis = 9;
        }
        else if (zaidejo_laivu_kordinates[1] == '9')
        {
            stulpelis = 10;
        }
    }


    void priskirti_atakos_reiksmes_eilutems_stulpeliams()
    {

        if (zaidejo_puolimo_kordinates[0] == 'a')
        {
            eilutes_puolimas = 0;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'b')
        {
            eilutes_puolimas = 1;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'c')
        {
            eilutes_puolimas = 2;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'd')
        {
            eilutes_puolimas = 3;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'e')
        {
            eilutes_puolimas = 4;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'f')
        {
            eilutes_puolimas = 5;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'g')
        {
            eilutes_puolimas = 6;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'h')
        {
            eilutes_puolimas = 7;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'i')
        {
            eilutes_puolimas = 8;
        }
        else if (zaidejo_puolimo_kordinates[0] == 'j')
        {
            eilutes_puolimas = 9;
        }

        if (zaidejo_puolimo_kordinates[1] == '0')
        {
            stulpelio_puolimas = 1;
        }
        else if (zaidejo_puolimo_kordinates[1] == '1')
        {
            stulpelio_puolimas = 2;
        }
        else if (zaidejo_puolimo_kordinates[1] == '2')
        {
            stulpelio_puolimas = 3;
        }
        else if (zaidejo_puolimo_kordinates[1] == '3')
        {
            stulpelio_puolimas = 4;
        }
        else if (zaidejo_puolimo_kordinates[1] == '4')
        {
            stulpelio_puolimas = 5;
        }
        else if (zaidejo_puolimo_kordinates[1] == '5')
        {
            stulpelio_puolimas = 6;
        }
        else if (zaidejo_puolimo_kordinates[1] == '6')
        {
            stulpelio_puolimas = 7;
        }
        else if (zaidejo_puolimo_kordinates[1] == '7')
        {
            stulpelio_puolimas = 8;
        }
        else if (zaidejo_puolimo_kordinates[1] == '8')
        {
            stulpelio_puolimas = 9;
        }
        else if (zaidejo_puolimo_kordinates[1] == '9')
        {
            stulpelio_puolimas = 10;
        }
    }

    void priskirti_kompiuterio_kordinates_abecelei()
    {
        if (kompiuterio_eilutes_puolimas == 0)
        {
            pirmoji_kompiuterio_kordinate = 'a';
        }
        else if (kompiuterio_eilutes_puolimas == 1)
        {
            pirmoji_kompiuterio_kordinate = 'b';
        }
        else if (kompiuterio_eilutes_puolimas == 2)
        {
            pirmoji_kompiuterio_kordinate = 'c';
        }
        else if (kompiuterio_eilutes_puolimas == 3)
        {
            pirmoji_kompiuterio_kordinate = 'd';
        }
        else if (kompiuterio_eilutes_puolimas == 4)
        {
            pirmoji_kompiuterio_kordinate = 'e';
        }
        else if (kompiuterio_eilutes_puolimas == 5)
        {
            pirmoji_kompiuterio_kordinate = 'f';
        }
        else if (kompiuterio_eilutes_puolimas == 6)
        {
            pirmoji_kompiuterio_kordinate = 'g';
        }
        else if (kompiuterio_eilutes_puolimas == 7)
        {
            pirmoji_kompiuterio_kordinate = 'h';
        }
        else if (kompiuterio_eilutes_puolimas == 8)
        {
            pirmoji_kompiuterio_kordinate = 'i';
        }
        else if (kompiuterio_eilutes_puolimas == 9)
        {
            pirmoji_kompiuterio_kordinate = 'j';
        }
    }



    void zaidejas_atakuoja_lenta()
    {
        if (zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] == '!' || zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] == '$')
        {
            atspausdinti_radarus();
            cout << setw(82) << "Jus jau atakavote sia kordinate.";
            Sleep(3000);
            teisingos_puolimo_kordinates = false;
        }
        else if (kompiuterio_lenta[eilutes_puolimas][stulpelio_puolimas] == 'V')
        {
            atspausdinti_radarus();
            cout << setw(84) << "Pataikete i vienvieti laiva.";
            zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] = '!';
            vienviecio_dydis--;
            kompiuterio_laivu_vietos_ant_lentos--;
            if(vienviecio_dydis==0) {
                    cout << setw(84) << "vienvietis numustas.";
                     zaidejo_atakos_radaras[eilutes_puolimas+1][stulpelio_puolimas] = '$';
                      zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas+1] = '$';
                       zaidejo_atakos_radaras[eilutes_puolimas+1][stulpelio_puolimas+1] = '$';
                        zaidejo_atakos_radaras[eilutes_puolimas-1][stulpelio_puolimas] = '$';
                         zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas-1] = '$';
                          zaidejo_atakos_radaras[eilutes_puolimas-1][stulpelio_puolimas-1] = '$';
                           zaidejo_atakos_radaras[eilutes_puolimas+1][stulpelio_puolimas-1] = '$';
                          zaidejo_atakos_radaras[eilutes_puolimas-1][stulpelio_puolimas+1] = '$';


            }
        }
        else if (kompiuterio_lenta[eilutes_puolimas][stulpelio_puolimas] == 'D')
        {
            atspausdinti_radarus();
            cout << setw(84) << "pataikete i dvivieti laiva.";
            zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] = '!';
           dviviecio_dydis--;
            kompiuterio_laivu_vietos_ant_lentos--;
            if(dviviecio_dydis==0) {
                    cout << setw(84) << "dvivietis numustas.";

            }
        }
        else if (kompiuterio_lenta[eilutes_puolimas][stulpelio_puolimas] == 'T')
        {
            atspausdinti_radarus();
            cout << setw(84) << "pataikete i trivieti laiva";
            zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] = '!';
            triviecio_dydis--;
            kompiuterio_laivu_vietos_ant_lentos--;
            if(triviecio_dydis==0) {
                    cout << setw(84) << "trivietis numustas.";

            }
        }
        else if (kompiuterio_lenta[eilutes_puolimas][stulpelio_puolimas] == 'K')
        {
            atspausdinti_radarus();
            cout << setw(84) << "pataikete i keturvieti laiva.";
            zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] = '!';
            keturviecio_dydis--;
            kompiuterio_laivu_vietos_ant_lentos--;
            if(keturviecio_dydis==0) {
                    cout << setw(84) << "keturvietis numustas.";

            }
        }
        else
        {
            atspausdinti_radarus();
            cout << setw(71) << "Nepataikete" << endl << endl;
            zaidejo_atakos_radaras[eilutes_puolimas][stulpelio_puolimas] = '$';
        }

    }




    void kompiuteris_atakuoja()
    {
        do
        {
            teisingos_kompiuterio_puolimo_kordinates = true;
            kompiuterio_eilutes_puolimas = rand() % 11;
            kompiuterio_stulpelio_puolimas = rand() % 11;

            if (dvivietis_pataikytas == true)
            {
                if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'D')
                {
                    kompiuteris_atakuoja_lenta();
                }
                else
                {
                    teisingos_kompiuterio_puolimo_kordinates = false;
                }
            }
            else if (trivietis_pataikytas == true)
            {
                if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'T')
                {
                    kompiuteris_atakuoja_lenta();
                }
                else
                {
                    teisingos_kompiuterio_puolimo_kordinates = false;
                }
            }
            else if (keturvietis_pataikytas == true)
            {
                if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'K')
                {
                    kompiuteris_atakuoja_lenta();
                }
                else
                {
                    teisingos_kompiuterio_puolimo_kordinates = false;
                }
            }
            else if (vienvietis_pataikytas == true)
            {
                if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'V')
                {
                    kompiuteris_atakuoja_lenta();
                }
                else
                {
                    teisingos_kompiuterio_puolimo_kordinates = false;
                }
            }
            if (dvivietis_pataikytas == false && trivietis_pataikytas == false
                    && keturvietis_pataikytas == false && vienvietis_pataikytas == false)
            {
                kompiuteris_atakuoja_lenta();
            }

        }
        while (!teisingos_kompiuterio_puolimo_kordinates || zaidejo_laivu_vietos_ant_lentos > 0);
    }


    void kompiuteris_atakuoja_lenta()
    {
        priskirti_kompiuterio_kordinates_abecelei();
        if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'V')
        {
            cout << setw(82) << "Kompiuteris pataike i jusu vienvieti laiva: " << pirmoji_kompiuterio_kordinate << kompiuterio_stulpelio_puolimas - 1 << endl << endl;
            vienvietis_pataikytas = true;
            zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] = '!';
            zaidejo_laivu_vietos_ant_lentos--;
            zaidejo_vienviecio_dydis--;
        }
        else if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'D')
        {
            cout << setw(81) << "Kompiuteris pataike i jusu dvivieti laiva: " << pirmoji_kompiuterio_kordinate << kompiuterio_stulpelio_puolimas - 1 << endl << endl;
            dvivietis_pataikytas = true;
            zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] = '!';
            zaidejo_dviviecio_dydis--;
            zaidejo_laivu_vietos_ant_lentos--;
        }
        else if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'T')
        {
            cout << setw(81) << "Kompiuteris pataike i jusu trivieti laiva: " << pirmoji_kompiuterio_kordinate << kompiuterio_stulpelio_puolimas - 1 << endl << endl;
            trivietis_pataikytas = true;
            zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] = '!';
            zaidejo_laivu_vietos_ant_lentos--;
            zaidejo_triviecio_dydis--;
        }
        else if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == 'K')
        {
            cout << setw(81) << "Kompiuteris pataike i jusu keturvieti laiva: " << pirmoji_kompiuterio_kordinate << kompiuterio_stulpelio_puolimas - 1 << endl << endl;
            keturvietis_pataikytas = true;
            zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] = '!';
            zaidejo_laivu_vietos_ant_lentos--;
            zaidejo_keturviecio_dydis--;
        }
        else if (zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] == '-')
        {
            cout << setw(73) << "Kompiuteris nepataike: " << pirmoji_kompiuterio_kordinate << kompiuterio_stulpelio_puolimas - 1 << endl << endl;
            zaidejo_lenta[kompiuterio_eilutes_puolimas][kompiuterio_stulpelio_puolimas] = '$';
        }
        else
        {
            teisingos_kompiuterio_puolimo_kordinates = false;

        }
        clear_hit();

        int * tekstas;
        if (zaidejo_laivu_vietos_ant_lentos == 0)
        {
            tekstas = new int [6];
            for ( int i = 0; i < 6; i++)
            {
                system("CLS");
                system("Color 2E");
                for (int i = 0; i < 19; i++)
                {
                    cout << endl;
                }
                Sleep(200);
                cout << setw(72) << "Kompiuteris laimejo " << endl;
                Sleep(500);

delete [] tekstas;
            }

exit(0);
        }
        else if (teisingos_kompiuterio_puolimo_kordinates == true)
        {
            Sleep(3000);
            zaidejas_atakuoja();
        }
    }

    void clear_hit()
    {
        if (zaidejo_vienviecio_dydis == 0)
        {
            vienvietis_pataikytas = false;
        }
        if (zaidejo_triviecio_dydis == 0)
        {
            trivietis_pataikytas = false;
        }
        if (zaidejo_dviviecio_dydis == 0)
        {
            dvivietis_pataikytas = false;
        }
        if (zaidejo_keturviecio_dydis == 0)
        {
            keturvietis_pataikytas = false;
        }
    }

    void Instrukcijos()
    {
        system("CLS");
        system("Color 03");
        cout << "Stalo žaidimas jūros kova yra labai paprastas, todėl visos šio žaidimo taisyklės gali būti atsispindi keliuose taškuose:" << endl;
        cout << " Prieš žaidimo pradžią, kiekvienas žaidėjas atkreipia savo lankstinuką į 10x10 kvadratų žaidimo lauką ir jame yra laivų, kuriuos sudaro tokie vienetai:" << endl;
        cout << "   1 keturių denio laivas, kuris atsispindi ant popieriaus kaip 4 ląstelių serija;" << endl;
        cout << "   1 trijų denių - 3 ląstelių eilės;" << endl;
        cout << "   1 dvigubas - 2 ląstelių eilės;" << endl;
        cout << "  1 vieno langelio - valtis" << endl;
        cout << " Visi laivai yra ant laukoši taisyklė: kiekvieno laivo deniai gali būti išdėstyti tik vertikaliai arba horizontaliai. Negalima dažyti lakštų įstrižai arba lenkimo. Be to, laivas neturėtų liesti kito net su kampu." << endl;
        cout << "  Žaidimo pradžioje su daugybe dalyviųNustatykite, kas pirmiausia eis. Savo ruožtu imamasi tolesnių veiksmų, tačiau sąlyga, kad tas, kuris palietė priešo laivą, tęsiasi. Jei žaidėjas nepasiekė nė vieno priešininko laivo, jis turi perkelti perėją į kitą." << endl;
        cout << " Žaidėjas, kuris atlieka judėjimą, vadina kombinacijąraidės ir skaičiai, nurodantys tariamą priešo laivo buvimo vietą. Jo oponentas įvertina savo žaidimo lauką, kur prasidėjo smūgis, ir informuoja antrąjį žaidėją, ar jis pateko į laivą, ar ne. " << endl;
        cout << "  Tokiu atveju, jei bet kuris laivyno elementas buvo užmirštas ar paliestas, ant lauko jis pažymėtas kryžiuku, o jei smūgis nukrito į tuščią narvą, taške įdedamas taškas." << endl;
        cout << "   Jūros mūšio žaidime laimi tas, kuris sugebėjo greičiau nuskęsti priešingos laivyno laivus. Tęsiant mūšį, pirmas žingsnis yra pralaimėtojas." << endl;

    }


    ~Laivu_musis(){
    }

};




int main()
{
    Laivu_musis b(0,0);
    Laivu_musis b1(b);
    Laivu_musis b2(false,false,false,false);
    b1.atspausdinti_meniu();
    b.zaidejas_pasirenka_meniu();
    b.Ivesti_varda();
    b.laivu_skaiciai();
    b.atspausdinti_radarus();
    b.zaidejo_ivestos_kordinates();
    b.ar_teisingos_kordinates();
    b.patikrinimas_del_pozicijos();
    b.horizontaliai_ar_vertikaliai();
    b.pradedame_zaidima();
    ++b;
    b.kompiuterio_patikrinimas_del_teisngos_pozicijos();
    b.kompiuteris_pasirenka_vertikaliai_ar_horizontaliai();
    b.zaidejas_atakuoja();
    b.patikrinimas_del_teisingu_atakos_kordinaciu();
    b.priskirti_atakos_reiksmes_eilutems_stulpeliams();
    b.priskirti_kompiuterio_kordinates_abecelei();
    b.zaidejas_atakuoja_lenta();
    b2.kompiuteris_atakuoja();
    b2.kompiuteris_atakuoja_lenta();
    b.clear_hit();
    b.Instrukcijos();

}
