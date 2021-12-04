/****************************************************************************
** Meta object code from reading C++ file 'signupscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/signupscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signupscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_signupscreen_t {
    const uint offsetsAndSize[34];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_signupscreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_signupscreen_t qt_meta_stringdata_signupscreen = {
    {
QT_MOC_LITERAL(0, 12), // "signupscreen"
QT_MOC_LITERAL(13, 15), // "OpenLoginScreen"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 18), // "LoginOnNextClicked"
QT_MOC_LITERAL(49, 5), // "uName"
QT_MOC_LITERAL(55, 5), // "pWord"
QT_MOC_LITERAL(61, 15), // "on_Next_clicked"
QT_MOC_LITERAL(77, 12), // "Signupclosed"
QT_MOC_LITERAL(90, 16), // "on_close_clicked"
QT_MOC_LITERAL(107, 23), // "on_Username_textChanged"
QT_MOC_LITERAL(131, 4), // "arg1"
QT_MOC_LITERAL(136, 20), // "on_email_textChanged"
QT_MOC_LITERAL(157, 21), // "on_cat_avatar_toggled"
QT_MOC_LITERAL(179, 7), // "checked"
QT_MOC_LITERAL(187, 21), // "on_pup_avatar_toggled"
QT_MOC_LITERAL(209, 24), // "on_jerboa_avatar_toggled"
QT_MOC_LITERAL(234, 11) // "checkValues"

    },
    "signupscreen\0OpenLoginScreen\0\0"
    "LoginOnNextClicked\0uName\0pWord\0"
    "on_Next_clicked\0Signupclosed\0"
    "on_close_clicked\0on_Username_textChanged\0"
    "arg1\0on_email_textChanged\0"
    "on_cat_avatar_toggled\0checked\0"
    "on_pup_avatar_toggled\0on_jerboa_avatar_toggled\0"
    "checkValues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_signupscreen[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    0 /* Public */,
       3,    2,   81,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   86,    2, 0x08,    4 /* Private */,
       7,    0,   87,    2, 0x08,    5 /* Private */,
       8,    0,   88,    2, 0x08,    6 /* Private */,
       9,    1,   89,    2, 0x08,    7 /* Private */,
      11,    1,   92,    2, 0x08,    9 /* Private */,
      12,    1,   95,    2, 0x08,   11 /* Private */,
      14,    1,   98,    2, 0x08,   13 /* Private */,
      15,    1,  101,    2, 0x08,   15 /* Private */,
      16,    0,  104,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,

       0        // eod
};

void signupscreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<signupscreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OpenLoginScreen(); break;
        case 1: _t->LoginOnNextClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_Next_clicked(); break;
        case 3: _t->Signupclosed(); break;
        case 4: _t->on_close_clicked(); break;
        case 5: _t->on_Username_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_email_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_cat_avatar_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_pup_avatar_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_jerboa_avatar_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->checkValues(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (signupscreen::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&signupscreen::OpenLoginScreen)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (signupscreen::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&signupscreen::LoginOnNextClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject signupscreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_signupscreen.offsetsAndSize,
    qt_meta_data_signupscreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_signupscreen_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *signupscreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *signupscreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_signupscreen.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int signupscreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void signupscreen::OpenLoginScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void signupscreen::LoginOnNextClicked(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
