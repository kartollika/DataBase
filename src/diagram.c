#include "../headers/diagram.h"

void showDiagramRadial(const participant *part, int mode, int column, int record)
{
    int sumint = 0;
    double sumdouble = 0;
    int angle = 0;
    int size;
    double persint, persdouble;
    int gd = CUSTOM, gm = CUSTOM_MODE(700, 400);
    initgraph(&gd, &gm, "");

    int i;
    char *s = calloc(30, sizeof(char));
    if (record < 10)
    {
        settextstyle(0, 0, 12);
        size = 35;
    }
    else
    {
        settextstyle(0, 0, 7);
        size = 25;
    }
    for (i=0; i<record; ++i)
    {
        sumint += part[i].place;
        sumdouble += part[i].average;
    }

    for (i=0; i<record; ++i)
    {
        setcolor(i+1);
        char *buf = calloc(30, sizeof(char));

        strcat(s, part[i].name);
        strcat(s, " ");
        strcat(s, part[i].surname);
        strcat(s, " - ");

        persint = (double)(part[i].place)/(double)(sumint);
        persdouble = (part[i].average)/(double)(sumdouble);

        if (column == 0)
        {
            if (i==record - 1)
                pieslice(200, getmaxy()/2, angle, 360, 130);
            else
                pieslice(200, getmaxy()/2, angle, angle + round(persint * 360), 130);
            sprintf(buf, "%.2lf", persint * 100);
            angle += round(persint * 360);
            strcat(s, buf);
            strcat(s, "%");
        }
        else
        {
            if (i == record - 1)
                pieslice(200, getmaxy()/2, angle, 360, 130);
            else
                pieslice(200, getmaxy()/2, angle, angle + round(persint * 360), 130);
            sprintf(buf, "%.2lf", persdouble * 100);
            angle += round(persdouble * 360);
            strcat(s, buf);
            strcat(s, "%");
        }

        outtextxy(410, 27 + i*size , s);
        s[0] = '\0';
    }
    readkey();
    closegraph();
}

void showDiagramColumn(const participant *part, int mode, int column, int record)
{
    int sumint = 0;
    int color = 1;
    double sumdouble = 0;
    int size = 1;
    double persint, persdouble;
    int left = 30;
    int right = 450;
    int between = 10;
    int bottom = 360;
    int top = 80;
    int width = (right - left) / (record) - between;

    int gd = CUSTOM, gm = CUSTOM_MODE(800, 400);
    initgraph(&gd, &gm, "");

    int i;
    char *s = calloc(30, sizeof(char));
    settextstyle(0, 0, 7);
    if (record < 10)
        size = 35;
    else
        size = 25;

    for (i=0; i<record; ++i)
    {
        sumint += part[i].place;
        sumdouble += part[i].average;
    }

    for (i=0; i<record; ++i)
    {
        if (!color)
            color = 1;
        setfillstyle(SOLID_FILL, color);

        char *buf = calloc(30, sizeof(char));

        strcat(s, part[i].name);
        strcat(s, " ");
        strcat(s, part[i].surname);
        strcat(s, " - ");

        persint = (double)(part[i].place)/(double)(sumint);
        persdouble = (part[i].average)/(double)(sumdouble);

        if (column == 0)
        {
            bar(left, bottom - (bottom-top) * (persint), left + width, bottom);
            sprintf(buf, "%.2lf", persint * 100);
            strcat(s, buf);
            strcat(s, "%");
            left += width + between;
        }
        else
        {
            bar(left, bottom - round(persdouble * 1000), left + width, bottom);
            sprintf(buf, "%.2lf", persdouble * 100);
            strcat(s, buf);
            strcat(s, "%");
            left += width + between;
        }

        setcolor(color++);
        outtextxy(right + 41, 27 + i* size , s);
        s[0] = '\0';
    }
    readkey();
    closegraph();
}
