#include <iostream.h>
#include <math.h>

int gcd(int x, int y)
{ 
    if(y == 0) return x;
    return gcd(y, x % y);
}

class Rat
{ 
public:
    Rat(int = 0, int = 1);
    Rat(const Rat&);
    void print() const;
    Rat operator-(const Rat&) const;
    Rat operator/(const Rat&) const;
    int numer() const;
    int denom() const;
    void setNum(int);
    void setDen(int);

private:
    int num;                     
    int den;                           
};

Rat::Rat(int n, int d)
{ 
    if(d == 0)
    { 
        num = n;
        den = 1;
    }
    else
    { 
        if(n == 0)
        { 
            num = 0;
            den = 1;
        }
        else
        { 
            int g = gcd(abs(n), abs(d));
            if(n > 0 && d > 0 || n < 0 && d < 0)
            { 
                num = abs(n)/g;
                den = abs(d)/g;
            }
            else
            { 
                num = -abs(n)/g;
                den =  abs(d)/g;
            }
        }
    }
}

int Rat::numer() const
{ 
    return num;
}

int Rat::denom() const
{
    return den;
}
void Rat::setNum(int n)
{ 
    num = n;
}

void Rat::setDen(int d)
{ 
    if(d != 0)
    {
        den = d;
    }
    else
    { 
        den = 1;
    }
}

void Rat::print() const
{ 
    cout << num << "/" << den;
}

Rat Rat::operator-(const Rat& r) const
{ 
    return Rat(num*r.den - den*r.num, den*r.den);
}

Rat Rat::operator/(const Rat& r) const
{ 
    return Rat(num*r.den, den*r.num);
}
int main()
{ 

    return 0;
}
