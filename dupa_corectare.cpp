#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1005;

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

    Vector_Complex(Complex a[], int numar)
    {
        nr_elemente = numar;

        for(int i = 0; i < numar; i++)
            v[i] = a[i];
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
    Complex Getk(int k){return v[k];}

    //setteri

    void SetNr(int numar) { nr_elemente = numar; }
    void SetRealk(int real, int k) { v[k].m_real = real; }
    void SetImagk(int imaginar, int k) { v[k].m_imaginar = imaginar; }
    void Setk(const Complex &nr, int k) { v[k] = nr; }



    //determinarea modulelor
    double *modul();

    //sortare elemente dupa modul
    void sortare();

    //suma elementelor vectorului
    Complex sume();

   /* vector<double> modul1()
    {
        vector<double>module;

        for(int i = 0; i < nr_elemente; i++)
            module.push_back(v[i].Abs());

        cout << "Modulele Vectorului : ";
        for(int i = 0; i < nr_elemente; i++)
            cout << module[i] << " ";

        cout << '\n' << '\n';
        return module;
    }


    void sortare1()
    {
        vector<double>m = modul1();


        for(int i = 0; i < nr_elemente - 1; i++)
            for(int j = i + 1; j < nr_elemente; j++)
                if(m[i] > m[j])
                {
                    double aux = m[i];
                    m[i] = m[j];
                    m[j] = aux;
                }

    cout << "Vectorul sortat crescator dupa module : ";
        for(int i = 0; i < nr_elemente; i++)
            cout << m[i] << ' ';
        cout << '\n' << '\n';
    }*/


    //functie citire

    friend std::istream &operator>>(std::istream &fin, Vector_Complex &vect)
    {
        cout << "Numarul de elemente din vector : "; fin >> vect.nr_elemente;

        for(int i = 0; i < vect.nr_elemente; i++)
        {
            cout << "Scrie partea reala apoi cea imaginara : ";
            fin >> vect.v[i];
        }
        cout << '\n';
        return fin;
    }

    //functie afisare

    friend std::ostream &operator<<(std::ostream &out, Vector_Complex &vect)
    {
        cout << "Numarul de elemente : ";
        out << vect.nr_elemente << '\n';
        cout << '\n';

        for(int i = 0; i < vect.nr_elemente; i++)
        {
            cout << "Element : ";
            out << vect.v[i];
        }
        cout << '\n';

        return out;
    }


};


Complex Vector_Complex::sume()
{
    Complex rezultat;
    for(int i = 0; i < nr_elemente; i++)
        rezultat = rezultat + v[i];

    return rezultat;
}


double* Vector_Complex::modul()
{
    double *m = new double[nr_elemente];

    for(int i = 0; i < nr_elemente; i++)
        m[i] = v[i].Abs();

    return m;
}


void Vector_Complex::sortare()
{
    //Vector_Complex a(v, nr_elemente);

    double* m = modul();
    Complex aux;

    for(int i = 0; i < nr_elemente - 1; i++)
        for(int j = i + 1; j < nr_elemente; j++)
            if(m[i] > m[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void ReadNComplexVectors()
{
    int numar_vectori;
    cout << "Citeste numarul de vectori :"; cin >> numar_vectori;
    cout << '\n';

    Vector_Complex *vect = new Vector_Complex[numar_vectori];
    for(int i = 0; i < numar_vectori; i++)
    {
        cin >> vect[i];
    }


    cout << "Ai citit " << numar_vectori << " vectori complexi" <<'\n' << '\n';
    for(int i = 0; i < numar_vectori; i++)
        cout << vect[i] << '\n';

}


int main()
{
    //Vector_Complex a(4, 10);
    //Vector_Complex a(64.2, 12.1, 15);

    Vector_Complex a;

    cin >> a;

    double *mod = a.modul();

    cout << "Modulele : ";
    for(int i = 0; i < 3; i++)
        cout << mod[i] << " ";
    cout << '\n' << '\n';

    a.sortare();

    Complex x;

    x = a.sume();

    cout << "Sume " << x << '\n';

    Complex c(3.21, 7.2);

    a.Setk(c, 1);

    c.SetReal(66);

    cout << a << c;

    //ReadNComplexVectors();


    return 0;
}
