/****************************************************************************
** Meta object code from reading C++ file 'adminuser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/adminuser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminuser_t {
    const uint offsetsAndSize[12];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_adminuser_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_adminuser_t qt_meta_stringdata_adminuser = {
    {
QT_MOC_LITERAL(0, 9), // "adminuser"
QT_MOC_LITERAL(10, 15), // "ClosedAdminHome"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 15), // "on_back_clicked"
QT_MOC_LITERAL(43, 18), // "on_adduser_clicked"
QT_MOC_LITERAL(62, 19) // "UpdateAdminUserSlot"

    },
    "adminuser\0ClosedAdminHome\0\0on_back_clicked\0"
    "on_adduser_clicked\0UpdateAdminUserSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminuser[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x08,    1 /* Private */,
       4,    0,   40,    2, 0x08,    2 /* Private */,
       5,    0,   41,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminuser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminuser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClosedAdminHome(); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->on_adduser_clicked(); break;
        case 3: _t->UpdateAdminUserSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (adminuser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&adminuser::ClosedAdminHome)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject adminuser::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_adminuser.offsetsAndSize,
    qt_meta_data_adminuser,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_adminuser_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *adminuser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminuser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminuser.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int adminuser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void adminuser::ClosedAdminHome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
