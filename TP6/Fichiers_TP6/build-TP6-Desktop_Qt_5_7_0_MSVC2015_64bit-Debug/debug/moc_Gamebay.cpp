/****************************************************************************
** Meta object code from reading C++ file 'Gamebay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TP6/Gamebay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gamebay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gamebay_t {
    QByteArrayData data[19];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gamebay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gamebay_t qt_meta_stringdata_Gamebay = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Gamebay"
QT_MOC_LITERAL(1, 8, 16), // "afficherAttaques"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 25), // "afficherCreaturesDresseur"
QT_MOC_LITERAL(4, 52, 15), // "changerCreature"
QT_MOC_LITERAL(5, 68, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 85, 17), // "afficherCreatures"
QT_MOC_LITERAL(7, 103, 17), // "afficherDresseurs"
QT_MOC_LITERAL(8, 121, 18), // "afficherInventaire"
QT_MOC_LITERAL(9, 140, 14), // "afficherCombat"
QT_MOC_LITERAL(10, 155, 17), // "afficherFinCombat"
QT_MOC_LITERAL(11, 173, 13), // "debuterCombat"
QT_MOC_LITERAL(12, 187, 4), // "item"
QT_MOC_LITERAL(13, 192, 9), // "Creature*"
QT_MOC_LITERAL(14, 202, 8), // "creature"
QT_MOC_LITERAL(15, 211, 23), // "attaquerCreatureAdverse"
QT_MOC_LITERAL(16, 235, 13), // "gestionDuMenu"
QT_MOC_LITERAL(17, 249, 15), // "afficherCapture"
QT_MOC_LITERAL(18, 265, 23) // "capturerCreatureAdverse"

    },
    "Gamebay\0afficherAttaques\0\0"
    "afficherCreaturesDresseur\0changerCreature\0"
    "QListWidgetItem*\0afficherCreatures\0"
    "afficherDresseurs\0afficherInventaire\0"
    "afficherCombat\0afficherFinCombat\0"
    "debuterCombat\0item\0Creature*\0creature\0"
    "attaquerCreatureAdverse\0gestionDuMenu\0"
    "afficherCapture\0capturerCreatureAdverse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gamebay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,   12,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gamebay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gamebay *_t = static_cast<Gamebay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->afficherAttaques(); break;
        case 1: _t->afficherCreaturesDresseur(); break;
        case 2: _t->changerCreature((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->afficherCreatures(); break;
        case 4: _t->afficherDresseurs(); break;
        case 5: _t->afficherInventaire(); break;
        case 6: _t->afficherCombat(); break;
        case 7: _t->afficherFinCombat(); break;
        case 8: _t->debuterCombat((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->debuterCombat((*reinterpret_cast< Creature*(*)>(_a[1]))); break;
        case 10: _t->attaquerCreatureAdverse(); break;
        case 11: _t->gestionDuMenu(); break;
        case 12: _t->afficherCapture(); break;
        case 13: _t->capturerCreatureAdverse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Creature* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Gamebay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gamebay.data,
      qt_meta_data_Gamebay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Gamebay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gamebay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Gamebay.stringdata0))
        return static_cast<void*>(const_cast< Gamebay*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gamebay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
