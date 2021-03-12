#include <bits/stdc++.h>
#define SIZE 1005

using namespace std;


class Vector_Complex;

class Complex {
    double m_real;
    double m_imaginar;

public:
    Complex() : m_real(0), m_imaginar(0) {}

    Complex(double real) : m_real(real), m_imaginar(0) {}

    Complex(double real, double imaginar) : m_real(real), m_imaginar(imaginar) {}

    Complex(Complex &complex) : m_real(complex.m_real), m_imaginar(complex.m_imaginar) {}

    ~Complex() {}

    Complex& operator=(const Complex& complex)
    {
        m_real = complex.m_real;
        m_imaginar = complex.m_imaginar;
        return *this;
    }

    // Getteri

    double GetReal() { return m_real; }
    double Getimaginar() { return m_imaginar; }

    // Setteri

    void SetReal(double real) { m_real = real; }
    void Setimaginar(double imaginar) { m_imaginar = imaginar; }

    // modulul unui numar complex

    double Abs() { return sqrt(m_real * m_real + m_imaginar * m_imaginar); }

    Complex operator+(Complex complex) {
        Complex result(m_real + complex.m_real, m_imaginar + complex.m_imaginar);
        return result;
    }

    friend Complex operator*(Complex c1, Complex c2);

    friend Complex operator/(Complex c1, Complex c2);

    friend std::istream &operator>>(std::istream &in, Complex &complex) {
        in >> complex.m_real >> complex.m_imaginar;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, Complex &complex) {
        if (complex.m_real != 0 && complex.m_imaginar != 0)
        {
            if (complex.m_imaginar < 0)
            {
                out << complex.m_real << " - i * " << -complex.m_imaginar << '\n';
            }
            else
            {
                out << complex.m_real << " + i * " << complex.m_imaginar << '\n';
            }
        }
        else if (complex.m_imaginar == 0)
        {
            out << complex.m_real << '\n';
        }
        else
        {
            if (complex.m_imaginar < 0) {
                out << " - i * " << -complex.m_imaginar << '\n';
            }
            else
                out << " i * " << complex.m_imaginar << '\n';
        }
        return out;
    }

    friend class Vector_Complex;

};

Complex operator*(Complex c1, Complex c2)
{
    Complex result;
    result.m_real = c1.m_real * c2.m_real - c1.m_imaginar * c2.m_imaginar;
    result.m_imaginar = c1.m_real * c2.m_imaginar + c1.m_imaginar * c2.m_real;
    return result;
}

Complex operator/(Complex c1, Complex c2)
{
    Complex result;
    Complex tmp(c2.m_real, -c2.m_imaginar);
    result = c1 * tmp;

    double nu = (c2.m_real * c2.m_real + c2.m_imaginar * c2.m_imaginar);
    result.m_real /= nu;
    result.m_imaginar /= nu;

    return result;
}


class Vector_Complex
{
    int nr_elemente;
    Complex v[SIZE];


public:
    //constructori
    Vector_Complex(): nr_elemente(0){}

    Vector_Complex(int numar)
    {
        for(int i = 0; i < numar; i++)
        {
            v[i].m_real = 0;
            v[i].m_imaginar = 0;
        }
    }

    Vector_Complex(double valoare, int numar)
    {
        nr_elemente = numar;
        for(int i = 0; i < numar; i++)
        {
            v[i].m_real = valoare;
            v[i].m_imaginar = valoare;
        }
    }

    Vector_Complex(double real, double imaginar, int numar)
    {
        nr_elemente = numar;
        for(int i = 0; i < numar; i++)
        {
            v[i].m_real = real;
            v[i].m_imaginar = imaginar;
        }
    }


    Vector_Complex(const Vector_Complex &a, int numar)
    {
        nr_elemente = numar;
        for(int i = 0; i < numar; i++)
        {
            v[i].m_real = a.v[i].m_real;
            v[i].m_imaginar = a.v[i].m_imaginar;

        }
    }

    //destructor

    ~Vector_Complex(){nr_elemente = 0;}

    //getteri

    int GetNr(){return nr_elemente;}
    double GetRealk(int k) {return v[k].m_real;}
    double GetImagk(int k) {return v[k].m_imaginar;}

    //setteri

    void SetNr(int numar) {nr_elemente = numar;}
    void SetRealk(int real, int k) {v[k].m_real = real;}
    void SetImagk(int imaginar, int k) {v[k].m_imaginar = imaginar;}


    //determinare a modulelor


    vector<double> modul(int numar)
    {
        vector<double>module;

        for(int i = 0; i < numar; i++)
            module.push_back(v[i].Abs());

        cout << "Modulele Vectorului : ";
        for(int i = 0; i < numar; i++)
            cout << module[i] << " ";

        cout << '\n' << '\n';
        return module;
    }


    //sortare crescatoare dupa modul

    void sortare(int numar)
    {
        vector<double>m = modul(numar);


        int indice[numar + 1];

        for(int i = 0; i < numar; i++)
            indice[i] = i;


        for(int i = 0; i < numar - 1; i++)
            for(int j = i + 1; j < numar; j++)
            {
                if(m[i] > m[j])
                {
                    swap(m[i], m[j]);
                    swap(indice[i], indice[j]);
                }
            }

        cout << "Vectorul sortat crescator dupa module : " << '\n';
        for(int i = 0; i < numar; i++)
            cout << indice[i]  << " cu valoarea " << m[i] << '\n';
        cout << '\n' << '\n';
    }

    //suma elementelor vectorului

    Complex sume(int numar)
    {
        cout << "Suma numerelor din vector : ";
        Complex rezultat;
        for(int i = 0; i < numar; i++)
            rezultat = rezultat + v[i];

        cout << rezultat;

        cout << '\n';

    }

    friend std::istream &operator>>(std::istream &fin, Vector_Complex &vect)
    {
        cout << "Numarul de numere din vector : "; fin >> vect.nr_elemente;

        cout << '\n';

        for(int i = 0; i < vect.nr_elemente; i++)
        {
            cout << "Scrie partea reala apoi cea imaginara : ";
            fin >> vect.v[i];
        }
        return fin;
    }


    friend std::ostream &operator<<(std::ostream &out, Vector_Complex &vect)
    {
        cout << "Numarul de elemente : ";
        out << vect.nr_elemente << '\n';
        cout << '\n';

        for(int i = 0; i < vect.nr_elemente; i++)
        {
            cout << "element : ";
            out << vect.v[i];
            cout << '\n';
        }

        return out;
    }


};



int main()
{
   // Vector_Complex a(4, 10);
    //Vector_Complex a(64.2, 12.1, 15);
    Vector_Complex a;

    cin >> a;

    cout << '\n';

    cout << "Numarul de elemente din vector este : " << a.GetNr() << '\n' << '\n';

    cout << "Partea reala a unui element " << a.GetRealk(1) << '\n' << '\n';

    cout << "Partea imaginara a unui element " << a.GetImagk(1) << '\n' << '\n';

    a.sume(a.GetNr());
    a.sortare(a.GetNr());

    cout << a;



    return 0;
}
    //a.modul(a.GetNr());
