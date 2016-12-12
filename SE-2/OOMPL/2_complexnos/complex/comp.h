#ifndef COMP_H
#define COMP_H

#endif // COMP_H
class comp
       {
        float real,img;
public:
        comp();
        comp(float,float);
        comp operator+(comp);
        comp operator-(comp);
        comp operator*(comp);
        friend comp operator/(comp c1,comp c2);

        friend class MainWindow;
         };
