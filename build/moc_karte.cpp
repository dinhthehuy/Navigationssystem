/****************************************************************************
** Meta object code from reading C++ file 'karte.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../app/karte.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'karte.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Karte_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Karte_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Karte_t qt_meta_stringdata_Karte = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Karte"
QT_MOC_LITERAL(1, 6, 20), // "QRadioButton_Clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 2), // "id"
QT_MOC_LITERAL(4, 31, 10), // "Entfernung"
QT_MOC_LITERAL(5, 42, 11), // "Information"
QT_MOC_LITERAL(6, 54, 16), // "AlleOrte_Clicked"
QT_MOC_LITERAL(7, 71, 13), // "Laden_Clicked"
QT_MOC_LITERAL(8, 85, 7), // "Routing"
QT_MOC_LITERAL(9, 93, 17), // "Speichern_Clicked"
QT_MOC_LITERAL(10, 111, 17), // "Verbinden_Clicked"
QT_MOC_LITERAL(11, 129, 10), // "OrtAnlegen"
QT_MOC_LITERAL(12, 140, 11) // "OrtLoeschen"

    },
    "Karte\0QRadioButton_Clicked\0\0id\0"
    "Entfernung\0Information\0AlleOrte_Clicked\0"
    "Laden_Clicked\0Routing\0Speichern_Clicked\0"
    "Verbinden_Clicked\0OrtAnlegen\0OrtLoeschen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Karte[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Karte::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Karte *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->QRadioButton_Clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Entfernung(); break;
        case 2: _t->Information(); break;
        case 3: _t->AlleOrte_Clicked(); break;
        case 4: _t->Laden_Clicked(); break;
        case 5: _t->Routing(); break;
        case 6: _t->Speichern_Clicked(); break;
        case 7: _t->Verbinden_Clicked(); break;
        case 8: _t->OrtAnlegen(); break;
        case 9: _t->OrtLoeschen(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Karte::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Karte.data,
    qt_meta_data_Karte,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Karte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Karte::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Karte.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Karte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
