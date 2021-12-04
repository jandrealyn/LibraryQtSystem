/****************************************************************************
** Meta object code from reading C++ file 'adminhome.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/adminhome.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminhome.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminhome_t {
    const uint offsetsAndSize[16];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_adminhome_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_adminhome_t qt_meta_stringdata_adminhome = {
    {
QT_MOC_LITERAL(0, 9), // "adminhome"
QT_MOC_LITERAL(10, 14), // "ClosedMainMenu"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 30), // "on_admin_catalogue_btn_clicked"
QT_MOC_LITERAL(57, 25), // "on_admin_user_btn_clicked"
QT_MOC_LITERAL(83, 27), // "on_admin_system_btn_clicked"
QT_MOC_LITERAL(111, 17), // "on_logout_clicked"
QT_MOC_LITERAL(129, 15) // "AdminHomeClosed"

    },
    "adminhome\0ClosedMainMenu\0\0"
    "on_admin_catalogue_btn_clicked\0"
    "on_admin_user_btn_clicked\0"
    "on_admin_system_btn_clicked\0"
    "on_logout_clicked\0AdminHomeClosed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminhome[] = {

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
       7,    0,   55,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminhome::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminhome *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClosedMainMenu(); break;
        case 1: _t->on_admin_catalogue_btn_clicked(); break;
        case 2: _t->on_admin_user_btn_clicked(); break;
        case 3: _t->on_admin_system_btn_clicked(); break;
        case 4: _t->on_logout_clicked(); break;
        case 5: _t->AdminHomeClosed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (adminhome::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&adminhome::ClosedMainMenu)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject adminhome::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_adminhome.offsetsAndSize,
    qt_meta_data_adminhome,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_adminhome_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *adminhome::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminhome::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminhome.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int adminhome::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void adminhome::ClosedMainMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
