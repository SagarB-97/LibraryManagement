const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};
class date
{
    int dd;
    int mm;
    int yyyy;

    int countLeapYears(date d)
    {
        int years = d.yyyy;
        if (d.mm <= 2)
            years--;
        return years / 4 - years / 100 + years / 400;
    }

    int getDifference(date dt1, date dt2)
    {
        long int n1 = dt1.yyyy*365 + dt1.dd;
        for (int i=0; i<dt1.mm - 1; i++)
            n1 += monthDays[i];
        n1 += countLeapYears(dt1);
        long int n2 = dt2.yyyy*365 + dt2.dd;
        for (int i=0; i<dt2.mm - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(dt2);
        return (n1 - n2);
    }


    public:
    date()
    {
        dd=mm=yyyy=0;
    }

    date(int d, int m, int y)
    {
        dd = d;
        mm = m;
        yyyy = y;
    }
    int operator- (date &d)
    {
        return getDifference(*this, d);
    }

  friend ostream& operator<<(ostream& cout,date& d);
  friend istream& operator>>(istream& in, date& d);
};

ostream& operator<<(ostream& cout,date& d)
{
    cout<<d.dd<<"/"<<d.mm<<"/"<<d.yyyy;
    return cout;
}
bool checkLeapYear(int year)
{
    if (year%400 == 0)
        return true;
    if (year%100 == 0)
        return false;
    if (year%4 == 0)
        return true;
    return false;
}
istream& operator>>(istream& in, date& d){
    cout<<"\n\t\t\t\t\t\tDate  :";in>>d.dd;
    cout<<"\n\t\t\t\t\t\tMonth :";in>>d.mm;
    cout<<"\n\t\t\t\t\t\tYear  :";in>>d.yyyy;
    if(d.dd<0 || d.mm<0 || d.yyyy<0){
        throw "Negative Date Error";
    }
    else if(d.mm>12){
        throw "Invalid Month Error";
    }
    else if(checkLeapYear(d.yyyy) && d.dd>29){
        throw "Invalid Date Error";
    }
    else if(d.dd>monthDays[d.mm-1]){
        throw "Invalid Date Error";
    }
    return in;
}
