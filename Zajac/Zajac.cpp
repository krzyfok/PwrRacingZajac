#include <iostream>
#include<string>
using namespace std;


void wczytywanie_znakow(string ** mapa, int w, int k, int &ref_x, int &ref_y, int &norax, int &noray)
{
    string znaki;
    
    getline(cin, znaki);
    for (int i = 0;i < w;i++) {
        getline(cin, znaki);
        for (int j = 0;j < k;j++) {
            mapa[i][j] = znaki[j];
            if (mapa[i][j] == "z")
            {
                ref_x = i;
                ref_y = j;
               
            }
            if (mapa[i][j] == "n")
            {
                norax = i;
                noray = j;
            }
            
        }
    }
}
void wyswietlanie(string** mapa, int w,int k)
{
    for (int i = 0;i < w;i++) {

        for (int j = 0;j < k;j++) {
            cout << mapa[i][j];
        }
        cout << endl;
    }
    
}


void symulacja2(string** mapa, int norax, int noray, int zx, int zy, int wiersz, int kolumna)
{
    int skoki[8][2] = { {1,2 },{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
    int pola[1000][2];
    int wykonaneskoki[1000][2];


    int k = 1;
    int zajacx = zx, zajacy = zy;
  
    int  j = 0;
    pola[0][0] = zx;
    pola[0][1] = zy;
  

    while (true)
    {
        
        if (j > k) {
            cout << "NIE";break;
        }
        zx = pola[j][0];
        zy = pola[j][1];
        for (int i = 0;i < 8;i++)
        {
            if ((zx + skoki[i][0]) >= 0 && (zx + skoki[i][0]) < wiersz && (zy + skoki[i][1]) >= 0 && (zy + skoki[i][1]) < kolumna)
            {
                if (mapa[zx + skoki[i][0]][zy + skoki[i][1]] == ".")
                {
                    
                   
                    pola[k][0] = zx + skoki[i][0];
                    pola[k][1] = zy + skoki[i][1];
                    
                    wykonaneskoki[k][0] = skoki[i][0];
                    wykonaneskoki[k][1] = skoki[i][1];
                    k++;
                   
                    mapa[zx + skoki[i][0]][zy + skoki[i][1]] ="b";
                }
                if (mapa[zx + skoki[i][0]][zy + skoki[i][1]] == "n")
                {
                
                    pola[k][0] = zx + skoki[i][0];
                    pola[k][1] = zy + skoki[i][1];
                    
                    wykonaneskoki[k][0] = skoki[i][0];
                    wykonaneskoki[k][1] = skoki[i][1];
                   
                    break;
                   
                }
            }
        }
        if (pola[k][0] == norax && pola[k][1] == noray)break;
        
        j++;
       
    }
    
   
    
    int x = pola[k][0], y = pola[k][1];
    
    int wynik = 0;
   
   
    if (j <= k)
    {      
        while (true)
        {
            if (x == zajacx && y == zajacy)
            {
                break;
            }         
            x = x - wykonaneskoki[k][0];
            y = y - wykonaneskoki[k][1];         
            while (true)
            {
                k--;
                if (x == pola[k][0] && y == pola[k][1])
                {
                    break;
                }
            }       
            wynik++;
        }
        cout << wynik;
    }   
}


int main()
{
    int w, k,pozycjax=0, pozycjay=0, norax=0, noray=0;
        
    cin >> w;
    cin >> k;
    
    string** mapa;
    mapa = new string * [w];
    for (int i = 0;i < w;i++)
    {
        mapa[i] = new string[k];
    }
   
    wczytywanie_znakow(mapa, w, k, pozycjax,pozycjay, norax,noray);
          
   symulacja2(mapa,norax,noray,pozycjax,pozycjay,w,k);
   
    
   for (int i = 0;i < w;i++)
   {
       delete[] mapa[i];
   }
    
    delete[] mapa;

}

