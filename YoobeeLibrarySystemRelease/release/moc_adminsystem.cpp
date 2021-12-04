/****************************************************************************
** Meta object code from reading C++ file 'adminsystem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/adminsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminsystem_t {
    const uint offsetsAndSize[14];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_adminsystem_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_adminsystem_t qt_meta_stringdata_adminsystem = {
    {
QT_MOC_LITERAL(0, 11), // "adminsystem"
QT_MOC_LITERAL(12, 15), // "ClosedAdminHome"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 15), // "on_back_clicked"
QT_MOC_LITERAL(45, 17), // "AdminSystemClosed"
QT_MOC_LITERAL(63, 24), // "on_admin_due_btn_clicked"
QT_MOC_LITERAL(88, 28) // "on_admin_overdue_btn_clicked"

    },
    "adminsystem\0ClosedAdminHome\0\0"
    "on_back_clicked\0AdminSystemClosed\0"
    "on_admin_due_btn_clicked\0"
    "on_admin_overdue_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminsystem[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   45,    2, 0x08,    1 /* Private */,
       4,    0,   46,    2, 0x08,    2 /* Private */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminsystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminsystem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClosedAdminHome(); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->AdminSystemClosed(); break;
        case 3: _t->on_admin_due_btn_clicked(); break;
        case 4: _t->on_admin_overdue_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (adminsystem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&adminsystem::ClosedAdminHome)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject adminsystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_adminsystem.offsetsAndSize,
    qt_meta_data_adminsystem,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_adminsystem_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *adminsystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminsystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminsystem.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int adminsystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void adminsystem::ClosedAdminHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
