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
    QByteArrayData data[22];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gamebay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gamebay_t qt_meta_stringdata_Gamebay = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Gamebay"
QT_MOC_LITERAL(1, 8, 22), // "CreatureAdverseVaincue"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "estVaincue"
QT_MOC_LITERAL(4, 43, 15), // "CreatureVaincue"
QT_MOC_LITERAL(5, 59, 16), // "afficherAttaques"
QT_MOC_LITERAL(6, 76, 25), // "afficherCreaturesDresseur"
QT_MOC_LITERAL(7, 102, 15), // "changerCreature"
QT_MOC_LITERAL(8, 118, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 135, 17), // "afficherCreatures"
QT_MOC_LITERAL(10, 153, 17), // "afficherDresseurs"
QT_MOC_LITERAL(11, 171, 18), // "afficherInventaire"
QT_MOC_LITERAL(12, 190, 14), // "afficherCombat"
QT_MOC_LITERAL(13, 205, 17), // "afficherFinCombat"
QT_MOC_LITERAL(14, 223, 13), // "debuterCombat"
QT_MOC_LITERAL(15, 237, 4), // "item"
QT_MOC_LITERAL(16, 242, 9), // "Creature*"
QT_MOC_LITERAL(17, 252, 8), // "creature"
QT_MOC_LITERAL(18, 261, 23), // "attaquerCreatureAdverse"
QT_MOC_LITERAL(19, 285, 13), // "gestionDuMenu"
QT_MOC_LITERAL(20, 299, 15), // "afficherCapture"
QT_MOC_LITERAL(21, 315, 23) // "capturerCreatureAdverse"

    },
    "Gamebay\0CreatureAdverseVaincue\0\0"
    "estVaincue\0CreatureVaincue\0afficherAttaques\0"
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
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  100,    2, 0x08 /* Private */,
       6,    0,  101,    2, 0x08 /* Private */,
       7,    1,  102,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    1,  110,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,
      20,    0,  118,    2, 0x08 /* Private */,
      21,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   15,
    QMetaType::Void, 0x80000000 | 16,   17,
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
        case 0: _t->CreatureAdverseVaincue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->CreatureVaincue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->afficherAttaques(); break;
        case 3: _t->afficherCreaturesDresseur(); break;
        case 4: _t->changerCreature((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->afficherCreatures(); break;
        case 6: _t->afficherDresseurs(); break;
        case 7: _t->afficherInventaire(); break;
        case 8: _t->afficherCombat(); break;
        case 9: _t->afficherFinCombat(); break;
        case 10: _t->debuterCombat((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->debuterCombat((*reinterpret_cast< Creature*(*)>(_a[1]))); break;
        case 12: _t->attaquerCreatureAdverse(); break;
        case 13: _t->gestionDuMenu(); break;
        case 14: _t->afficherCapture(); break;
        case 15: _t->capturerCreatureAdverse(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Creature* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Gamebay::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gamebay::CreatureAdverseVaincue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Gamebay::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gamebay::CreatureVaincue)) {
                *result = 1;
                return;
            }
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Gamebay::CreatureAdverseVaincue(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gamebay::CreatureVaincue(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
