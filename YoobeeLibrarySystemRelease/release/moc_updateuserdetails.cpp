/****************************************************************************
** Meta object code from reading C++ file 'updateuserdetails.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/updateuserdetails.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updateuserdetails.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UpdateUserDetails_t {
    const uint offsetsAndSize[20];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UpdateUserDetails_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UpdateUserDetails_t qt_meta_stringdata_UpdateUserDetails = {
    {
QT_MOC_LITERAL(0, 17), // "UpdateUserDetails"
QT_MOC_LITERAL(18, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(63, 7), // "checked"
QT_MOC_LITERAL(71, 25), // "on_confirmChanges_clicked"
QT_MOC_LITERAL(97, 32), // "on_lineEdit_username_textChanged"
QT_MOC_LITERAL(130, 4), // "arg1"
QT_MOC_LITERAL(135, 29), // "on_lineEdit_email_textChanged"
QT_MOC_LITERAL(165, 11) // "checkValues"

    },
    "UpdateUserDetails\0on_pushButton_2_clicked\0"
    "\0on_checkBox_toggled\0checked\0"
    "on_confirmChanges_clicked\0"
    "on_lineEdit_username_textChanged\0arg1\0"
    "on_lineEdit_email_textChanged\0checkValues"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpdateUserDetails[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    1,   51,    2, 0x08,    1 /* Private */,
       5,    0,   54,    2, 0x08,    3 /* Private */,
       6,    1,   55,    2, 0x08,    4 /* Private */,
       8,    1,   58,    2, 0x08,    6 /* Private */,
       9,    0,   61,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void UpdateUserDetails::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UpdateUserDetails *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_confirmChanges_clicked(); break;
        case 3: _t->on_lineEdit_username_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_email_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->checkValues(); break;
        default: ;
        }
    }
}

const QMetaObject UpdateUserDetails::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_UpdateUserDetails.offsetsAndSize,
    qt_meta_data_UpdateUserDetails,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UpdateUserDetails_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *UpdateUserDetails::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpdateUserDetails::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UpdateUserDetails.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UpdateUserDetails::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
