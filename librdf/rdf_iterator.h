/*
 * rdf_iterator.h - RDF Iterator definition
 *
 * $Source$
 * $Id$
 *
 * (C) Dave Beckett 2000 ILRT, University of Bristol
 * http://www.ilrt.bristol.ac.uk/people/cmdjb/
 *
 *                                       
 * This program is free software distributed under either of these licenses:
 *   1. The GNU Lesser General Public License (LGPL)
 * OR ALTERNATIVELY
 *   2. The modified BSD license
 *
 * See LICENSE.html or LICENSE.txt for the full license terms.
 */



#ifndef LIBRDF_ITERATOR_H
#define LIBRDF_ITERATOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *context;
	int (*have_elements)(void*);
	void* (*get_next)(void*);
	void (*finished)(void*);
} librdf_iterator;


librdf_iterator* librdf_new_iterator(void *datum,
				     int (*have_elements)(void*),
				     void* (*get_next)(void*),
				     void (*finished)(void*));
void librdf_free_iterator(librdf_iterator*);

int librdf_iterator_have_elements(librdf_iterator* iterator);

void* librdf_iterator_get_next(librdf_iterator* iterator);


#ifdef __cplusplus
}
#endif

#endif
