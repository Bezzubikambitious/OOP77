#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include<QStandardItemModel>
#include<QTableView>
#include <math.h>
#include <QPlainTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_check_clicked();

    void on_bulean_clicked();

    void on_max_clicked();

    void on_min_clicked();

    void on_add_clicked();

    void on_substract_clicked();

    void on_union_2_clicked();

    void on_set1_clicked();

    void on_set2_clicked();

    void on_crossing_clicked();

    void on_show_Memo1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QStandardItemModel* model1;
    QStandardItemModel* model2;
    QStandardItemModel* model3;
};

class Set{
    int *m_num;
    int m_length;

public:
    Set(){}
    Set(int length)   //ініціалізація нулями
    {
        m_length = length;
        m_num = new int[m_length];
        for(int i = 0; i<m_length; i++)
        {
            m_num[i] = 0;
        }
    }

    Set(int *array, int length)     //присвоєння значень з масиву
    {
        m_length = length;
        m_num = new int[m_length];
        for(int i = 0; i<m_length; i++)
        {
            m_num[i] = array[i];
        }
    }

    Set(const Set &other) //Конструктор копіювання
    {
             this->m_length = other.m_length;
             this->m_num = new int [other.m_length];
             for (int i=0;i< m_length;i++)
             {
                 this->m_num[i]=other.m_num[i];
             }
    }

    ~Set() //Деструктор для видалення динамічної памёяті
        {
            delete[] m_num;
        }

    int GetValue(int i)
    {
        return m_num[i];
    }

    int Check(int number)
    {
        for(int i = 0; i<this->m_length; i++)
        {
            if(number == this->m_num[i])
            {
                return 1;
            }
        }
        return 0;
    }

    int Bulean()
    {
        int power = this->m_length;
        int bulean = pow(2, power);
        return bulean;
    }

    int MaxNegative()
    {
        int res=0;
        for(int i =0; i<this->m_length; i++)
        {
            if(this->m_num[i]<res)
            {
                res = this->m_num[i];
            }
        }
        return res;
    }

    int MinPositive()
    {
        int res = 10000;
        for(int i = 0; i<this->m_length; i++)
        {
            if(this->m_num[i]<res && this->m_num[i]>0)
            {
                res = this->m_num[i];
            }
        }
        return res;
    }

    int MaxMod()
    {
        int res = fabs(this->m_num[0]);
        for(int i = 1; i<this->m_length; i++)
        {
            if(fabs(this->m_num[i])>res)
            {
                res = fabs(this->m_num[i]);
            }
        }
        return res;
    }

    void addElement(int number)
    {
        int check = 0;
        for(int i = 0; i<this->m_length; i++)
        {
            if(this->Check(number))
            {
                check = 1;
            }
        }
        if(!check)
        {
            this->m_length = this->m_length+1;
            this->m_num[this->m_length-1] = number;
        }
    }

    Set* subElement(int number)
    {
        Set *s1 = new Set(this->GetLength()-1);
        int k = 0;
        for(int i = 0; i<this->m_length; i++)
        {
            if(this->m_num[i] != number)
            {
                s1->m_num[k] = this->m_num[i];
                k++;
            }
        }
        s1->SetLength(k);
        return s1;
    }

    Set operator+(Set s1)
    {
        Set *s2 = new Set(this->m_length + s1.m_length);
        int k = 0;
        for(int i = 0; i<this->m_length; i++)
        {
            if(!(s2->Check(this->m_num[i])))
            {
                s2->m_num[k] = this->m_num[i];
                k++;
            }
         }
        for(int j = 0; j < s1.m_length; j++)
        {
            if(!s2->Check(s1.m_num[j]))
            {
                 s2->m_num[k] = s1.m_num[j];
                 k++;
            }
        }
        s2->m_length = k;
        return *s2;
    }

    Set operator-(Set s1)
    {
        Set *s2 = new Set(this->m_length);
        int k =0;
        for(int i = 0; i<this->m_length; i++)
        {
            for(int j = 0; j<s1.m_length; j++)
            {
                if(this->m_num[i] == s1.m_num[j])
                {
                    s2->m_num[k] = this->m_num[i];
                    k++;
                    break;
                }
            }
        }
        s2->m_length = k;
        return *s2;
    }

    int operator==(Set s1)
    {
        int check = 0;
        if(this->m_length != s1.m_length)
            return 0;
        for(int i = 0; i<this->m_length; i++)
        {
            for(int j = 0; j<s1.m_length; j++)
            {
                if(this->m_num[i] == s1.m_num[j])
                {
                    check++;
                }
            }
        }
        if(check == this->m_length)
            return 1;
        else
            return 0;
    }

    Set& operator=(const Set& obj1)
        {
        if (m_num != obj1.m_num)
            {
            if (obj1.m_length != m_length)
               {
                delete[] m_num; // Видаляємо старі елементи
                m_length = obj1.m_length;  // встановлюєм новий розмір масиву
                m_num = new int[obj1.m_length];  // виділяємо нову памёять для нашого масиву
               }
            // Копіюємо елементи в потрібний нам масив
            int *p = m_num + m_length;
            int *q = obj1.m_num + m_length;
            while (p > m_num)
                 *--p = *--q;
            }
        return *this;
        }

    void operator>>(QStandardItemModel* model)
    {
        QVariant myData;
        QModelIndex myIndex;

        for(int i = 0; i<this->m_length; i++)
        {
            myIndex = model->index(i, 0);
            myData = model->data(myIndex, Qt::DisplayRole);
            this->m_num[i] = myData.toInt();
        }
    }

    friend void operator<<(QStandardItemModel* model, Set &s1)
    {
        for(int i = 0; i< s1.m_length; i++)
        {
           model->setData(model->index(i, 0), s1.m_num[i]);
        }
    }

    friend void operator<<(QPlainTextEdit* edit, Set &s1)
    {
        edit->setPlainText("");
        QString str;
        for(int i = 0; i < s1.m_length; ++i)
        {
            str += QString::number(s1.m_num[i]);
            str += " ";
        }
         edit->setPlainText(str);
    }

    void clear(QStandardItemModel* model)
    {
        int row = this->GetLength();
        model->setData(model->index(row, 0), "");
    }

    int* Get_Set()
    {
        int *set = this->m_num;
        return set;
    }

    int GetLength()
    {
        int length = this->m_length;
        return length;
    }

    void SetLength(int length)
    {
        this->m_length = length;
    }

};

#endif // MAINWINDOW_H
