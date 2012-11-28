/****************************************************************************
** Meta object code from reading C++ file 'NewEmployer.h'
**
** Created: Wed Nov 28 11:55:10 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Source/NewEmployer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NewEmployer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewEmployer[] = {

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
      13,   12,   12,   12, 0x0a,
      22,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NewEmployer[] = {
    "NewEmployer\0\0cancel()\0submit()\0"
};

void NewEmployer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewEmployer *_t = static_cast<NewEmployer *>(_o);
        switch (_id) {
        case 0: _t->cancel(); break;
        case 1: _t->submit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewEmployer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewEmployer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewEmployer,
      qt_meta_data_NewEmployer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewEmployer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewEmployer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewEmployer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewEmployer))
        return static_cast<void*>(const_cast< NewEmployer*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewEmployer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
