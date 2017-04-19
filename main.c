#include <stdio.h>
#include <stdlib.h>
#include "headers/baseFunc.h"
#include "headers/file_inout.h"
#include <GL/glut.h>

void drawText()
{
        glMatrixMode(GL_PROJECTION);
     //   double *matrix = new double[16];
     //   glGetDoublev(GL_PROJECTION_MATRIX, matrix);
        glLoadIdentity();
        glOrtho(0,400,0,400,-5,5);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(40,40);
        int i;
        for(i=0; i<20; i++)
        {
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int) 'A');
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
//        glLoadMatrixd(matrix);
    //    glMatrixMode(GL_MODELVIEW);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.4, 0.4, 1.0);
    glBegin(GL_LINES);
        glVertex2f(110, 40);
        glVertex2f(220, 200);
        glVertex2f(110, 40);
        glVertex2f(220, 40);
        glVertex2f(110, 200);
        glVertex2f(220, 200);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int) 'A');
    glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    int record, task = 1;
    participant *participants = NULL;
    FILE *f = NULL;

  /*  glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(320, 240);
    glutCreateWindow("");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 320, 0, 240);

    glutDisplayFunc(drawText);
    glutMainLoop();
*/
  //  char k;
  //  scanf("%c", &k);
   // printf("%i", (char) k);

    {
        TEST_count_Record();
        printf("ALL TESTS SUCCESSFUL\n"
               "READY TO WORK\n");
    }

    while ( 1 )
    {
        printf("\nChoose your operation with database\n"
               "    1) Create new database\n"
               "    2) Load database from file\n"
               "    3) Save database in same file\n"
               "    4) Print database on console\n"
               "    5) Print specific record by identifier\n"
               "    6) Add new records to database\n"
               "    7) Delete records from database\n"
               "    8) Edit record in database\n"
               "    9) Sort database by specific field\n"
               "Other) Exit\n");

        scanf("%i", &task);
        printf("\n");
        switch(task)
        {
        case 1:
            {
                if (!f)
                {
                    f = initFILE(0);
                    if (!f) continue;
                    record = recordsCount(f);
                    participants = (participant*) malloc(record * sizeof(participant));
                }
                continue;
            }
        case 2:
            {
                if (!f)
                {
                    f = initFILE(1);
                    record = recordsCount(f);
                    participants = (participant*) malloc(record * sizeof(participant));
                    scanFILE(f, participants, &record);
                }

                continue;
            }
        case 3:
            {
                if (f)
                    printFILE(f, participants, &record);
                else
                    printf("DATABASE HASN'T FOUND\n");

                continue;
            }
        case 4:
            {
                if (f)
                    printConsole(participants, &record);
                else
                    printf("DATABASE HASN'T FOUND\n");
                continue;
            }
        case 5:
            {
                int id;
                scanf("%i", &id);
                printUser(&participants[id-1]);
                continue;
            }
        case 6:
            {
                if (f)
                {
                    int count;
                    printf("Enter count of new records\nCount = ");
                    scanf("%i", &count);
                    participants = addRecord(participants, &record, &count);
                }
                else
                    printf("DATABASE HASN'T FOUND\n");

                continue;
            }
        case 7:
            {
                if (f)
                {
                    int pos, count;
                    printf("From what position do you want to delete record?\n"
                           "And how many do you want to delete? (F.E 3 2 (from 3 position delete 2 records\n");
                    scanf("%i %i", &pos, &count);
                    participants = delRecord(participants, &pos, &count, &record);
                }
                else
                    printf("DATABASE HAS'T FOUND\n");

                continue;
            }
        case 8:
            {
                editRecord(participants);
                continue;
            }
        case 9:
            {
                printf("%c", participants[0].name[0]);
                int field, mode;
                printf("Choose column to sort database by this field\n"
                       "1 - Name 2 - Surname 3 - Place 4 - Average\n");
                scanf("%i", &field);
            //    printf("Choose mode to sort\n"
            //           "0 - increasing 1 - decreasing\n");
           //     scanf("%i", &mode);
                sortBase(participants, &field, &mode, &record);

                continue;
            }
        default:
            {
                int THELASTCHANCETOSAVEDATABASE;
                printf("DO YOU WANT TO SAVE YOUR DATABASE?\n"
                       "1 - YES, 0 - NO\n");
                scanf("%i", &THELASTCHANCETOSAVEDATABASE);

                if (THELASTCHANCETOSAVEDATABASE)
                    closeFILE(f);

                return 0;
            }
        }
    }
    return 0;
}
