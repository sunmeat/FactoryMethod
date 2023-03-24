#include <iostream>
using namespace std;

// Абстрактный класс для продуктов-диалогов
class Dialog {
public:
    virtual void Render() = 0;
    virtual void Click() = 0;
};

// Конкретный продукт диалога для Windows
class WindowsDialog : public Dialog {
public:
    void Render() override {
        cout << "Отрисовка Windows-диалога" << endl;
    }

    void Click() override {
        cout << "Клик на Windows-диалоге" << endl;
    }
};

// Конкретный продукт диалога для Web
class WebDialog : public Dialog {
public:
    void Render() override {
        cout << "Отрисовка Web-диалога" << endl;
    }

    void Click() override {
        cout << "Клик на Web-диалоге" << endl;
    }
};

// Конкретный продукт диалога для консоли
class ConsoleDialog : public Dialog {
public:
    void Render() override {
        cout << "Отрисовка консольного диалога" << endl;
    }

    void Click() override {
        cout << "Клик на консольном диалоге" << endl;
    }
};

// Абстрактный класс для создания продуктов диалогов
class DialogFactory {
public:
    virtual Dialog* CreateDialog() = 0;
};

// Конкретная фабрика для создания продуктов диалогов Windows
class WindowsDialogFactory : public DialogFactory {
public:
    Dialog* CreateDialog() override {
        return new WindowsDialog();
    }
};

// Конкретная фабрика для создания продуктов диалогов Web
class WebDialogFactory : public DialogFactory {
public:
    Dialog* CreateDialog() override {
        return new WebDialog();
    }
};

// Конкретная фабрика для создания продуктов диалогов консоли
class ConsoleDialogFactory : public DialogFactory {
public:
    Dialog* CreateDialog() override {
        return new ConsoleDialog();
    }
};

// Клиентский код
int main() {
    setlocale(0, "");

    DialogFactory* factory = new WindowsDialogFactory();
    Dialog* dialog = factory->CreateDialog();

    dialog->Render();
    dialog->Click();

    delete dialog;
    delete factory;
}

/*
Код содержит реализацию паттерна Фабричный метод
(Factory Method), который позволяет создавать объекты
без указания конкретного класса объекта, который будет
создан.

Классы WindowsDialog, WebDialog и ConsoleDialog - это
конкретные продукты, которые наследуются от абстрактного
класса Dialog, представляющего собой продукт-диалог.
Каждый продукт реализует методы Render() и Click(),
которые выполняют определенные действия в зависимости
от конкретной реализации продукта.

Классы WindowsDialogFactory, WebDialogFactory и
ConsoleDialogFactory - это конкретные фабрики, которые
реализуют абстрактный метод CreateDialog() для создания
продукта-диалога. Каждая фабрика создает конкретный
продукт-диалог соответствующего типа.

В клиентском коде создается экземпляр фабрики
WindowsDialogFactory, затем вызывается метод
CreateDialog(), который создает объект WindowsDialog
и возвращает указатель на него. Далее вызываются методы
Render() и Click() у объекта WindowsDialog.

Используя этот подход, можно добавлять новые
конкретные продукты и фабрики, не изменяя код клиента,
а только расширяя базовые абстрактные классы.
Это упрощает поддержку и масштабирование кода.
*/

// https://refactoring.guru/ru/design-patterns/factory-method

/*
Фабричный метод — это порождающий паттерн проектирования,
который определяет общий интерфейс для создания объектов
в суперклассе, позволяя подклассам изменять тип
создаваемых объектов.

Преимущества и недостатки
+ Избавляет класс от привязки к конкретным классам
продуктов.
+ Выделяет код производства продуктов в одно место,
упрощая поддержку кода.
+ Упрощает добавление новых продуктов в программу.
+ Реализует принцип открытости/закрытости.
- Может привести к созданию больших параллельных
иерархий классов, так как для каждого класса продукта
надо создать свой подкласс создателя.
*/