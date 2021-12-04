/****************************************************************************
** Meta object code from reading C++ file 'loginscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/loginscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_loginscreen_t {
    const uint offsetsAndSize[20];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_loginscreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_loginscreen_t qt_meta_stringdata_loginscreen = {
    {
QT_MOC_LITERAL(0, 11), // "loginscreen"
QT_MOC_LITERAL(12, 12), // "OpenMainMenu"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 16), // "on_login_clicked"
QT_MOC_LITERAL(43, 17), // "on_Create_clicked"
QT_MOC_LITERAL(61, 16), // "on_close_clicked"
QT_MOC_LITERAL(78, 15), // "LoginScreenOpen"
QT_MOC_LITERAL(94, 18), // "LoginThroughSignup"
QT_MOC_LITERAL(113, 5), // "uName"
QT_MOC_LITERAL(119, 5) // "pWord"

    },
    "loginscreen\0OpenMainMenu\0\0on_login_clicked\0"
    "on_Create_clicked\0on_close_clicked\0"
    "LoginScreenOpen\0LoginThroughSignup\0"
    "uName\0pWord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginscreen[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x08,    1 /* Private */,
       4,    0,   52,    2, 0x08,    2 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    2,   55,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,

       0        // eod
};

void loginscreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<loginscreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OpenMainMenu(); break;
        case 1: _t->on_login_clicked(); break;
        case 2: _t->on_Create_clicked(); break;
        case 3: _t->on_close_clicked(); break;
        case 4: _t->LoginScreenOpen(); break;
        case 5: _t->LoginThroughSignup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (loginscreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&loginscreen::OpenMainMenu)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject loginscreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_loginscreen.offsetsAndSize,
    qt_meta_data_loginscreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_loginscreen_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *loginscreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginscreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_loginscreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int loginscreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void loginscreen::OpenMainMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
