/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../restaurant/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_menu_t {
    QByteArrayData data[13];
    char stringdata0[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menu_t qt_meta_stringdata_menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "menu"
QT_MOC_LITERAL(1, 5, 18), // "on_Ajouter_clicked"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 19), // "on_ajouter1_clicked"
QT_MOC_LITERAL(4, 45, 29), // "on_supprimer_employee_clicked"
QT_MOC_LITERAL(5, 75, 28), // "on_modifier_employee_clicked"
QT_MOC_LITERAL(6, 104, 27), // "on_supprimer_profil_clicked"
QT_MOC_LITERAL(7, 132, 26), // "on_modifier_profil_clicked"
QT_MOC_LITERAL(8, 159, 23), // "on_tri_employee_clicked"
QT_MOC_LITERAL(9, 183, 8), // "sendMail"
QT_MOC_LITERAL(10, 192, 8), // "mailSent"
QT_MOC_LITERAL(11, 201, 27), // "on_colone_tri_textActivated"
QT_MOC_LITERAL(12, 229, 4) // "arg1"

    },
    "menu\0on_Ajouter_clicked\0\0on_ajouter1_clicked\0"
    "on_supprimer_employee_clicked\0"
    "on_modifier_employee_clicked\0"
    "on_supprimer_profil_clicked\0"
    "on_modifier_profil_clicked\0"
    "on_tri_employee_clicked\0sendMail\0"
    "mailSent\0on_colone_tri_textActivated\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        menu *_t = static_cast<menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Ajouter_clicked(); break;
        case 1: _t->on_ajouter1_clicked(); break;
        case 2: _t->on_supprimer_employee_clicked(); break;
        case 3: _t->on_modifier_employee_clicked(); break;
        case 4: _t->on_supprimer_profil_clicked(); break;
        case 5: _t->on_modifier_profil_clicked(); break;
        case 6: _t->on_tri_employee_clicked(); break;
        case 7: _t->sendMail(); break;
        case 8: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_colone_tri_textActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject menu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_menu.data,
      qt_meta_data_menu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_menu.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
