#pragma once
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include "clsDate.h"

class clsInputValidate
{


public:
    static int ReadPositiveIntNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        int number = 1;
        do {

            std::cout << message;
            std::cin >> number;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                std::cin >> number;
            }
        } while (number < 0);


        return number;
    }

    static float ReadPositiveFloatNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        float number = 1;
        do {

            std::cout << message;
            std::cin >> number;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                std::cin >> number;
            }
        } while (number < 0);


        return number;
    }
    static double ReadPositiveDoubleNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        double number = 1;
        do {

            std::cout << message;
            std::cin >> number;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                std::cin >> number;
            }
        } while (number < 0);


        return number;
    }
    static int ReadPositiveNumberInRange(std::string message, int From, int To, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        int number = 1;
        do {

            std::cout << message;
            if (!(std::cin >> number)) {
                // التعامل مع فشل الإدخال (إذا أدخل المستخدم نصًا أو نوعًا غير صحيحًا)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                continue; // العودة لبداية الحلقة لقراءة جديدة
            }
            else if (number < From || number > To)
            {
                std::cout << "Number is not withing the range, ";
                continue;
            }
        } while (number < From || number > To);


        return number;
    }
    static float ReadFloatNumberInRange(std::string message, float From, float To, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        float number = 1.0f; // تهيئة بقيمة افتراضية
        do {
            // طباعة الرسالة وطلب الإدخال
            std::cout << message;

            // محاولة قراءة الرقم
            if (!(std::cin >> number)) {
                // التعامل مع فشل الإدخال (إذا أدخل المستخدم نصًا أو نوعًا غير صحيحًا)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                continue; // العودة لبداية الحلقة لقراءة جديدة
            }
            else if (number < From || number > To)
            {
                std::cout << "Number is not withing the range, ";
                continue;
            }
            // التحقق من أن القيمة ضمن النطاق
        } while (number < From || number > To);

        // التحقق من وجود بقايا في المخزن المؤقت (لمنع المشاكل في الإدخالات اللاحقة)
        // هذا جزء مهم عند استخدام std::cin 
        // إذا لم يتم استخدام هذه السطور، قد تظهر مشاكل في إدخالات لاحقة
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return number;
    }
    static double ReadDoubleNumberInRange(std::string message, double From, double To, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        double number = 1.0; // تهيئة بقيمة افتراضية
        do {
            // طباعة الرسالة وطلب الإدخال
            std::cout << message;

            // محاولة قراءة الرقم
            if (!(std::cin >> number)) {
                // التعامل مع فشل الإدخال (إذا أدخل المستخدم نصًا أو نوعًا غير صحيحًا)
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << ErrorMessage;
                continue; // العودة لبداية الحلقة لقراءة جديدة
            }
            else if (number < From || number > To)
            {
                std::cout << "Number is not withing the range, ";
                continue;
            }

            // التحقق من أن القيمة ضمن النطاق
        } while (number < From || number > To);

        // التحقق من وجود بقايا في المخزن المؤقت (لمنع المشاكل في الإدخالات اللاحقة)
        // هذا جزء مهم عند استخدام std::cin 
        // إذا لم يتم استخدام هذه السطور، قد تظهر مشاكل في إدخالات لاحقة
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return number;
    }

    static int ReadValidNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        int number = 0;
        std::cout << message;
        std::cin >> number;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << ErrorMessage;
            std::cin >> number;
        }
        return number;
    }


    static float ReadValidFloatNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        float number = 0.0f; // القيمة الافتراضية

        std::cout << message;

        // محاولة قراءة الرقم
        std::cin >> number;

        // حلقة معالجة أخطاء الإدخال
        while (std::cin.fail()) {
            // 1. مسح علامة الفشل في مجرى الإدخال
            std::cin.clear();

            // 2. تجاهل جميع الأحرف المتبقية في المخزن المؤقت (حتى نهاية السطر)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // 3. طباعة رسالة الخطأ
            std::cout << ErrorMessage;

            // 4. محاولة قراءة الرقم مرة أخرى
            std::cin >> number;
        }

        // تنظيف المخزن المؤقت بعد الإدخال الصحيح (لمنع المشاكل في الإدخالات اللاحقة)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return number;
    }

    static double ReadValidDoubleNumber(std::string message, std::string ErrorMessage = "Invlaud input, r-enter: ") {
        double number = 0.0; // القيمة الافتراضية

        std::cout << message;

        // محاولة قراءة الرقم
        std::cin >> number;

        // حلقة معالجة أخطاء الإدخال
        while (std::cin.fail()) {
            // 1. مسح علامة الفشل في مجرى الإدخال
            std::cin.clear();

            // 2. تجاهل جميع الأحرف المتبقية في المخزن المؤقت (حتى نهاية السطر)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // 3. طباعة رسالة الخطأ
            std::cout << ErrorMessage;

            // 4. محاولة قراءة الرقم مرة أخرى
            std::cin >> number;
        }

        // تنظيف المخزن المؤقت بعد الإدخال الصحيح (لمنع المشاكل في الإدخالات اللاحقة)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return number;
    }

    static bool IsNumberBetween(const int& number, const int& from, const int& to)
    {
        return number >= from && number <= to;
    }
    static bool IsNumberBetween(const float& number, const float& from, const float& to)
    {
        return number >= from && number <= to;
    }

    static bool IsDateBetween(const clsDate& CurrentDate, const clsDate& Date1, clsDate Date2)
    {
        return (clsDate::IsDate1AfterDate2(CurrentDate, Date1) || clsDate::IsDate1EqualToDate2(CurrentDate, Date1)) && (clsDate::IsDate1LessThenDate2(CurrentDate, Date2) || clsDate::IsDate1EqualToDate2(CurrentDate, Date2));
    }

    static bool isValidDate(clsDate Date)
    {
        return clsDate::isValidDate(Date);
    }

    static std::string ReadString(const std::string& message)
    {
        std::string text = "";
        std::cout << message;
        std::getline(std::cin >> std::ws, text);
        return text;
    }
    static char ReadLetter(const std::string &Message) {
        char letter;
        std::cout << Message;
        std::cin >> letter;
        return letter;
    }

    bool ReadYesOrNo(const std::string &message,char answer)
    {
        return toupper(answer) == 'Y';
    }



};

