
#include <ctype.h>
#include <string.h>

#include "CsimpleXml.h"

namespace engine { namespace xml{
CsimpleXml::CsimpleXml(const char *encoded, const CsimpleXml *parent)
{
	const char *sptr, *tptr, *uptr;
	char *buf, *end, lastc;
	long len;
	keyvalue_rec *ptr;

	_parent = parent;

	_key = NULL;
	_value = NULL;
	_properties = NULL;
	_children = NULL;

	ptr = NULL;

	// decode the xml string

	sptr = strchr(encoded,'<');
	if (sptr==NULL)
		return;

	sptr++;
	len = ntotok(sptr,"> \t\r\n");
	_key = new char[len+1];
	strncpy(_key,sptr,len);
	_key[len] = 0;

	sptr += len;
	lastc = sptr[0];

	/** Parse parameters ************************************************/
	while (sptr && sptr[0] && lastc != '>') {
		len = nskiptok(sptr,"/> \t\r\n");
		lastc = sptr[len-1];
		sptr += len;

		if (lastc=='>' || sptr==NULL)
			break;

		if (lastc=='/' && sptr[0]=='>') {
			sptr += 2;
			break;
		}

		len = ntotok(sptr,"=");
		if (sptr[len]=='=' && sptr[len+1]) {
			if (_properties==NULL) {
				_properties = new keyvalue_rec;
				ptr = _properties;
			} else {
				ptr->next = new keyvalue_rec;
				ptr = ptr->next;
			}
			ptr->next = NULL;
			ptr->key = new char[len+1];
			strncpy(ptr->key, sptr, len);
			ptr->key[len] = 0;

			sptr += len+1;
			if (sptr[0]=='"') {
				sptr++;
				len = ntotok(sptr,"\"");
				ptr->value = new char[len+1];
				strncpy((char *)ptr->value,sptr,len);
				((char *)ptr->value)[len] = 0;
				sptr += len+1;
			} else {
				len = ntotok(sptr,"> \t\r\n");
				ptr->value = new char[len+1];
				strncpy((char *)ptr->value,sptr,len);
				((char *)ptr->value)[len] = 0;
				sptr += len;
			}
			if (sptr)
				lastc = sptr[0];
		}
	}

	// Empty tag?  <foo/>
	if (lastc=='/') {
		return;
	}

	if (lastc=='>') {
		sptr++;
	}

	len = nskiptok(sptr,"> \t\r\n");

	if (!sptr[len])
		return;

	// skip comments before determining tag type
	while (strncasecmp(&sptr[len],"<!--",4)==0) {
		sptr = stristr(&sptr[len],"-->") + 3;
		len = 0;
	}

	if (sptr[len]=='<') {

		sptr += len;
		buf = new char[strlen(_key) + 4]; // 4 => "</>\0"
		sprintf(buf,"</%s>",_key);

		while (sptr && strncasecmp(sptr,buf,strlen(buf))) {
			tptr = strchr(sptr,'<');
			if (tptr==NULL) {
				delete[] buf;
				return;
			}
			tptr++;
			len = ntotok(tptr,"> \t\r\n");
			if (_children==NULL) {
				_children = new keyvalue_rec;
				ptr = _children;
			} else {
				ptr->next = new keyvalue_rec;
				ptr = ptr->next;
			}
			ptr->next = NULL;
			ptr->key = new char[len+1];
			strncpy(ptr->key,tptr,len);
			ptr->key[len] = 0;
			ptr->value = new CsimpleXml(sptr,this);

			end = new char[len + 4]; // 4 => "</>\0"
			sprintf(end,"</%s>",ptr->key);
			sptr = stristr(sptr,end);
			sptr += strlen(end);
			delete[] end;

			sptr = strchr(sptr,'<');
		}

		delete[] buf;

	} else {

		buf = new char[strlen(_key) + 4]; // 4 => "</>\0"
		sprintf(buf,"</%s>",_key);
		tptr = stristr(sptr,buf);
		delete[] buf;

		if (tptr==NULL) {
			len = strlen(sptr);
			_value = new char[len+1];
			strcpy(_value,sptr);
		} else {
			len = tptr - sptr;
			_value = new char[len+1];
			strncpy(_value,sptr,len);
			_value[len] = 0;
		}
	}
}

long ntotok(const char *str, const char *tokens)
{
	long i;

	if (str==NULL)
		return -1;

	if (tokens==NULL)
		return 0;

	for (i=0; str[i] && strchr(tokens,str[i])==NULL; i++);

	return i;
}

long nskiptok(const char *str, const char *tokens)
{
	long i;

	if (str==NULL)
		return -1;

	if (tokens==NULL)
		return 0;

	for (i=0; str[i] && strchr(tokens,str[i])!=NULL; i++);

	return i;
}

const char *stristr(const char *haystack, const char *needle)
{
        long i, n;

        for (i=0; haystack[i]; i++) {
                if (tolower(haystack[i])==tolower(needle[0])) {
                        for (n=0;
                                haystack[i+n] && needle[n]
                                && tolower(haystack[i+n])==tolower(needle[n]);
                                        n++);
                        if (n==strlen(needle))
                                return(&haystack[i]);
                }
        }
        return NULL;
}

CsimpleXml::~CsimpleXml(void)
{
	keyvalue_rec *ptr,*last;

	if (_key!=NULL) {
		delete[] _key;
	}

	if (_value!=NULL) {
		delete[] _value;
	}

	if (_properties!=NULL) {
		for (ptr=_properties->next, last=_properties;
			ptr!=NULL;
				last=ptr, ptr=ptr->next) {
			delete[] last->key;
			delete[] (char *) last->value;
			delete last;
		}
		delete[] last->key;
		delete[] (char *) last->value;
		delete last;
	}

	if (_children!=NULL) {
		for (ptr=_children->next, last=_children;
			ptr!=NULL;
				last=ptr, ptr=ptr->next) {
			delete[] last->key;
			delete (CsimpleXml *) last->value;
			delete last;
		}
		delete[] last->key;
		delete (CsimpleXml *) last->value;
		delete last;
	}
}

const CsimpleXml *CsimpleXml::parent(void)
{
	return((const CsimpleXml *) _parent);
}

const char *CsimpleXml::key(void)
{
	return((const char *) _key);
}

const char *CsimpleXml::value(void)
{
	return((const char*) _value);
}

int CsimpleXml::number_of_properties(void)
{
	int i;
	keyvalue_rec *ptr;

	for (i=0, ptr=_properties; ptr!=NULL; i++, ptr=ptr->next);

	return i;
}

const char *CsimpleXml::property(int property_number)
{
	int i;
	keyvalue_rec *ptr;

	for (i=0, ptr=_properties;
		i!=property_number && ptr!=NULL;
			i++, ptr=ptr->next);

	if (ptr)
		return (const char *) ptr->value;
	else
		return NULL;
}

const char *CsimpleXml::property(const char *key, int iter)
{
	int i;
	keyvalue_rec *ptr;

	for (ptr=_properties; ptr!=NULL; ptr=ptr->next) {
		if (strcmp(ptr->key,key)==0) {
			for (i=0; i<iter && ptr!=NULL; i++, ptr=ptr->next);
			if (ptr)
				return (const char *) ptr->value;
			else
				return NULL;
		}
	}
	return NULL;
}

int CsimpleXml::number_of_children(void)
{
	int i;
	keyvalue_rec *ptr;

	for (i=0, ptr=_children; ptr!=NULL; i++, ptr=ptr->next);

	return i;
}

CsimpleXml *CsimpleXml::child(int child_number)
{
	int i;
	keyvalue_rec *ptr;

	for (i=0, ptr=_children;
		i!=child_number && ptr!=NULL;
			i++, ptr=ptr->next);

	if (ptr)
		return (CsimpleXml *) ptr->value;
	else
		return NULL;
}

CsimpleXml *CsimpleXml::child(const char *key, int iter)
{
	int i;
	keyvalue_rec *ptr;

	for (ptr=_children; ptr!=NULL; ptr=ptr->next) {
		if (strcmp(ptr->key,key)==0) {
			for (i=0; i<iter && ptr!=NULL; i++, ptr=ptr->next);
			if (ptr)
				return (CsimpleXml *) ptr->value;
			else
				return NULL;
		}
	}
	return NULL;
}
}
}
