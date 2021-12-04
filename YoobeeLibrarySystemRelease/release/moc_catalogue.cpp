/****************************************************************************
** Meta object code from reading C++ file 'catalogue.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/catalogue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'catalogue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Catalogue_t {
    const uint offsetsAndSize[18];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Catalogue_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Catalogue_t qt_meta_stringdata_Catalogue = {
    {
QT_MOC_LITERAL(0, 9), // "Catalogue"
QT_MOC_LITERAL(10, 12), // "OpenMainMenu"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 29), // "on_yourAccount_logout_clicked"
QT_MOC_LITERAL(54, 24), // "on_searchBar_textChanged"
QT_MOC_LITERAL(79, 4), // "arg1"
QT_MOC_LITERAL(84, 29), // "on_yourAccount_update_clicked"
QT_MOC_LITERAL(114, 17), // "display_catalogue"
QT_MOC_LITERAL(132, 17) // "update_usersBooks"

    },
    "Catalogue\0OpenMainMenu\0\0"
    "on_yourAccount_logout_clicked\0"
    "on_searchBar_textChanged\0arg1\0"
    "on_yourAccount_update_clicked\0"
    "display_catalogue\0update_usersBooks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Catalogue[] = {

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
       4,    1,   52,    2, 0x08,    2 /* Private */,
       6,    0,   55,    2, 0x08,    4 /* Private */,
       7,    0,   56,    2, 0x08,    5 /* Private */,
       8,    0,   57,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Catalogue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Catalogue *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OpenMainMenu(); break;
        case 1: _t->on_yourAccount_logout_clicked(); break;
        case 2: _t->on_searchBar_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_yourAccount_update_clicked(); break;
        case 4: _t->display_catalogue(); break;
        case 5: _t->update_usersBooks(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Catalogue::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Catalogue::OpenMainMenu)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Catalogue::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Catalogue.offsetsAndSize,
    qt_meta_data_Catalogue,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Catalogue_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Catalogue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Catalogue::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Catalogue.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Catalogue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Catalogue::OpenMainMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
