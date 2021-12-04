/****************************************************************************
** Meta object code from reading C++ file 'reservebook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../YoobeeLibrarySystem/reservebook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reservebook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReserveBook_t {
    const uint offsetsAndSize[18];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ReserveBook_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ReserveBook_t qt_meta_stringdata_ReserveBook = {
    {
QT_MOC_LITERAL(0, 11), // "ReserveBook"
QT_MOC_LITERAL(12, 19), // "ReserveScreenClosed"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 27), // "Res_UpdateUsersCurrentBooks"
QT_MOC_LITERAL(61, 19), // "CloseCheckOutScreen"
QT_MOC_LITERAL(81, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(99, 25), // "on_calendarWidget_clicked"
QT_MOC_LITERAL(125, 4), // "date"
QT_MOC_LITERAL(130, 25) // "on_confirmReserve_clicked"

    },
    "ReserveBook\0ReserveScreenClosed\0\0"
    "Res_UpdateUsersCurrentBooks\0"
    "CloseCheckOutScreen\0on_cancel_clicked\0"
    "on_calendarWidget_clicked\0date\0"
    "on_confirmReserve_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReserveBook[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    0 /* Public */,
       3,    0,   51,    2, 0x06,    1 /* Public */,
       4,    0,   52,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    1,   54,    2, 0x08,    4 /* Private */,
       8,    0,   57,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    7,
    QMetaType::Void,

       0        // eod
};

void ReserveBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReserveBook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ReserveScreenClosed(); break;
        case 1: _t->Res_UpdateUsersCurrentBooks(); break;
        case 2: _t->CloseCheckOutScreen(); break;
        case 3: _t->on_cancel_clicked(); break;
        case 4: _t->on_calendarWidget_clicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 5: _t->on_confirmReserve_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReserveBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReserveBook::ReserveScreenClosed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReserveBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReserveBook::Res_UpdateUsersCurrentBooks)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReserveBook::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReserveBook::CloseCheckOutScreen)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ReserveBook::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ReserveBook.offsetsAndSize,
    qt_meta_data_ReserveBook,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ReserveBook_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ReserveBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReserveBook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReserveBook.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReserveBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ReserveBook::ReserveScreenClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ReserveBook::Res_UpdateUsersCurrentBooks()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ReserveBook::CloseCheckOutScreen()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
