/****************************************************************************
** Meta object code from reading C++ file 'FindEmployer.h'
**
** Created: Wed Nov 28 11:55:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/FindEmployer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FindEmployer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindEmployer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FindEmployer[] = {
    "FindEmployer\0\0findEmployer()\0cancel()\0"
};

void FindEmployer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FindEmployer *_t = static_cast<FindEmployer *>(_o);
        switch (_id) {
        case 0: _t->findEmployer(); break;
        case 1: _t->cancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FindEmployer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FindEmployer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FindEmployer,
      qt_meta_data_FindEmployer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindEmployer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindEmployer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindEmployer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindEmployer))
        return static_cast<void*>(const_cast< FindEmployer*>(this));
    return QDialog::qt_metacast(_clname);
}

int FindEmployer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
