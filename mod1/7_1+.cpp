 #include <iostream>
 

 struct athlet
 {
    int mass;
    int force;
 };

/*
 void mysort(athlet*& athlets, int size)
 {
    athlet buf;
    bool flag = false;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if((athlets[j].mass > athlets[j+1].mass) || (athlets[j].mass == athlets[j+1].mass && athlets[j].force < athlets[j+1].force))
            {
                flag = true;
                buf = athlets[j];
                athlets[j] = athlets[j+1];
                athlets[j+1] = buf;
            }
        }
        if(flag == false)
        break;
    }
 }*/

void myQsort(athlet*& a ,int l, int r)
{
    athlet x = a[l + (r - l) / 2];
    //запись эквивалентна (l+r)/2, 
    //но не вызввает переполнения на больших данных
    int i = l;
    int j = r;
    //код в while обычно выносят в процедуру particle
    while(i <= j)
    {
        while(a[i].mass < x.mass || (a[i].mass == x.mass && a[i].force > x.force)) i++;
        while(a[j].mass > x.mass || (a[j].mass == x.mass && a[j].force < x.force)) j--;
        if(i <= j)
        {
            athlet buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }
    }
    if (i<r)
        myQsort(a,i, r);
    
    if (l<j)    
        myQsort(a,l, j);    
}
 int getMaxH(athlet*& athlets, int size)
 {  
     int summass = 0;
     int count = 0;
     for(int i = 0; i < size; i++)
     {
         if(athlets[i].force > summass)
         {
             count++;
             summass += athlets[i].mass;
         }
     }
     return count;
 }
 
 int main()
 {
    int size = 20;
    athlet* athlets = new athlet[size];
    int mass;
    int force;
    int i = 0;
    while(std::cin >> mass >> force)
    {
        if(i == size)
        {
            athlet* athlets2 = new athlet[size*2];
            for(int j = 0; j < size; j++)
            {
                athlets2[j].mass = athlets[j].mass;
                athlets2[j].force = athlets[j].force;
            }
            delete[] athlets;
            athlets = athlets2;
            size *= 2;
        }
        athlets[i].mass = mass;
        athlets[i].force = force;
        i++;
    }
    //mysort(athlets,i);
    myQsort(athlets,0,i-1);
    std::cout << getMaxH(athlets,i);
    delete[] athlets;
    return 0;
 }