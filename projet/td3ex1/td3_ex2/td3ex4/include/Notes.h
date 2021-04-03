#ifndef NOTES_H
#define NOTES_H


class Notes
{

//
    public:
        Notes();
       Notes(float ,float ,float ,float ,float,float);
        Notes(float,float,float,float,float);
        float calculMoyenne();
        virtual ~Notes();

    protected:

    private:
float test1;
float test2;
float ds;
float examen;
float orale;
float tp;
bool avectp;
float calculNCC();
};

#endif // NOTES_H
