/*
 *    modified from below by setupx
 *
 *    strmap version 2.0.1
 *
 *    ANSI C hash table for strings.
 *
 *	  Version history:
 *	  1.0.0 - initial release
 *	  2.0.0 - changed function prefix from strmap to sm to ensure
 *	      ANSI C compatibility
 *	  2.0.1 - improved documentation 
 *
 *    strmap.h
 *
 *    Copyright (c) 2009, 2011, 2013 Per Ola Kristensson.
 *
 *    Per Ola Kristensson <pok21@cam.ac.uk> 
 *    Inference Group, Department of Physics
 *    University of Cambridge
 *    Cavendish Laboratory
 *    JJ Thomson Avenue
 *    CB3 0HE Cambridge
 *    United Kingdom
 *
 *    strmap is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    strmap is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with strmap.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _STR2INTMAP_H_
#define _STR2INTMAP_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 20
#define DEFAULT_CAPACITY 128
	
typedef struct sihash sihash;

/*
 * This callback function is called once per key-value when iterating over
 * all keys associated to values.
 *
 * Parameters:
 *
 * key: A pointer to a null-terminated C string. The string must not
 * be modified by the client.
 *
 * value: A pointer to a null-terminated C string. The string must
 * not be modified by the client.
 *
 * obj: A pointer to a client-specific object. This parameter may be
 * null.
 *
 * Return value: None.
 */
	typedef void(*sihash_enum_func)(const char *key, const int value);

/*
 * Creates a string map.
 *
 * Parameters:
 *
 * capacity: The number of top-level slots this string map
 * should allocate. This parameter must be > 0.
 *
 * Return value: A pointer to a string map object, 
 * or null if a new string map could not be allocated.
 */
sihash * sihash_new(unsigned int capacity);

/*
 * Releases all memory held by a string map object.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 * If the supplied string map has been previously released, the
 * behaviour of this function is undefined.
 *
 * Return value: None.
 */
void sihash_delete(sihash *map);

/*
 * Returns the value associated with the supplied key.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * key: A pointer to a null-terminated C string. This parameter cannot
 * be null.
 *
 * Return value: value, if NULL return 0
 */

	int sihash_get(const sihash *map, const char *key);

/*
 * Queries the existence of a key.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * key: A pointer to a null-terminated C string. This parameter cannot
 * be null.
 *
 * Return value: 1 if the key exists, 0 otherwise.
 */
int sihash_exists(const sihash *map, const char *key);

/*
 * Associates a value with the supplied key. If the key is already
 * associated with a value, the previous value is replaced.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * key: A pointer to a null-terminated C string. This parameter
 * cannot be null. The string must have a string length > 0. The
 * string will be copied.
 *
 * value: A pointer to a null-terminated C string. This parameter
 * cannot be null. The string must have a string length > 0. The
 * string will be copied.
 *
 * Return value: 1 if the association succeeded, 0 otherwise.
 */
void sihash_put(sihash *map, const char *key, int value);

/*
 * Returns the number of associations between keys and values.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 */
int sihash_get_count(const sihash *map);

/*
 * An enumerator over all associations between keys and values.
 *
 * Parameters:
 *
 * map: A pointer to a string map. This parameter cannot be null.
 *
 * enum_func: A pointer to a callback function that will be
 * called by this procedure once for every key associated
 * with a value. This parameter cannot be null.
 *
 * obj: A pointer to a client-specific object. This parameter will be
 * passed back to the client's callback function. This parameter can
 * be null.
 *
 * Return value: 1 if enumeration completed, 0 otherwise.
 */
	int sihash_enum(const sihash *map, sihash_enum_func enum_func);

#ifdef __cplusplus
}
#endif

#endif



/*strmap.c*/

typedef struct Pair Pair;

typedef struct Bucket Bucket;


struct Pair {
	char key[20];
	int value;
};

struct Bucket {
	unsigned int count;
	Pair *pairs;
};

struct sihash {
	unsigned int count;
	Bucket *buckets;
};

static Pair * get_pair(Bucket *bucket, const char *key);
static unsigned long hash(const char *str);

sihash * sihash_new(unsigned int capacity)
{
	sihash *map;
	
	map = malloc(sizeof(sihash));
	if (map == NULL) {
		return NULL;
	}
	map->count = capacity;
	map->buckets = malloc(map->count * sizeof(Bucket));
	if (map->buckets == NULL) {
		free(map);
		return NULL;
	}
	memset(map->buckets, 0, map->count * sizeof(Bucket));
	return map;
}

void sihash_delete(sihash *map)
{
	unsigned int i, j, n, m;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return;
	}
	n = map->count;
	bucket = map->buckets;
	i = 0;
	while (i < n) {
		m = bucket->count;
		free(bucket->pairs);
		bucket++;
		i++;
	}
	free(map->buckets);
	free(map);
}

int sihash_get(const sihash *map, const char *key)
{
	unsigned int index;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return 0;
	}
	if (key == NULL) {
		return 0;
	}
	index = hash(key) % map->count;
	bucket = &(map->buckets[index]);
	pair = get_pair(bucket, key);
	if (pair == NULL) {
		return 0;
	}
	return pair->value;
}

int sihash_exists(const sihash *map, const char *key)
{
	unsigned int index;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return 0;
	}
	if (key == NULL) {
		return 0;
	}
	index = hash(key) % map->count;
	bucket = &(map->buckets[index]);
	pair = get_pair(bucket, key);
	if (pair == NULL) {
		return 0;
	}
	return 1;
}
void sihash_incr(sihash *map, const char *key){
	unsigned int key_len, value_len, index;
  Bucket *bucket;
  Pair *tmp_pairs, *pair;
  char *tmp_value;
	index = hash(key) % map->count;
  bucket = &(map->buckets[index]);
  /* Check if we can handle insertion by sihashply replacing
   * an existing value in a key-value pair in the bucket.
   */
  if ((pair = get_pair(bucket, key)) != NULL) {
    /* The bucket contains a pair that matches the provided key,
     * change the value for that pair to the new value.*/

    pair->value++;
    return;
  }
	/* Create a key-value pair */
	if (bucket->count == 0) {
		/* The bucket is empty, lazily allocate space for a single
		 * key-value pair.
		 */
		bucket->pairs = malloc(sizeof(Pair));
		if (bucket->pairs == NULL) {
			return;
		}
		bucket->count = 1;
	}
	else {
		/* The bucket wasn't empty but no pair existed that matches the provided
		 * key, so create a new key-value pair.
		 */
		tmp_pairs = realloc(bucket->pairs, (bucket->count + 1) * sizeof(Pair));
		if (tmp_pairs == NULL) {
			return;
		}
		bucket->pairs = tmp_pairs;
		bucket->count++;
	}
	/* Get the last pair in the chain for the bucket */
	pair = &(bucket->pairs[bucket->count - 1]);
	strcpy(pair->key, key);
	pair->value = 1;

}

void sihash_put(sihash *map, const char *key, const int value)
{
	unsigned int key_len, value_len, index;
	Bucket *bucket;
	Pair *tmp_pairs, *pair;
	char *tmp_value;


	if (map == NULL) {
		return;
	}
	if (key == NULL) {
		return;
	}
//	value_len = strlen(value);
	/* Get a pointer to the bucket the key string hashes to */
	index = hash(key) % map->count;
	bucket = &(map->buckets[index]);
	/* Check if we can handle insertion by sihashply replacing
	 * an existing value in a key-value pair in the bucket.
	 */
	if ((pair = get_pair(bucket, key)) != NULL) {
		/* The bucket contains a pair that matches the provided key,
		 * change the value for that pair to the new value.*/
		 
		pair->value = value;
		return;
	}

	/* Create a key-value pair */
	if (bucket->count == 0) {
		/* The bucket is empty, lazily allocate space for a single
		 * key-value pair.
		 */
		bucket->pairs = malloc(sizeof(Pair));
		if (bucket->pairs == NULL) {
			return;
		}
		bucket->count = 1;
	}
	else {
		/* The bucket wasn't empty but no pair existed that matches the provided
		 * key, so create a new key-value pair.
		 */
		tmp_pairs = realloc(bucket->pairs, (bucket->count + 1) * sizeof(Pair));
		if (tmp_pairs == NULL) {
			return;
		}
		bucket->pairs = tmp_pairs;
		bucket->count++;
	}
	/* Get the last pair in the chain for the bucket */
	pair = &(bucket->pairs[bucket->count - 1]);
	strcpy(pair->key, key);
	pair->value = value;
}

int sihash_get_count(const sihash *map)
{
	unsigned int i, j, n, m;
	unsigned int count;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return 0;
	}
	bucket = map->buckets;
	n = map->count;
	i = 0;
	count = 0;
	while (i < n) {
		pair = bucket->pairs;
		m = bucket->count;
		j = 0;
		while (j < m) {
			count++;
			pair++;
			j++;
		}
		bucket++;
		i++;
	}
	return count;
}

int sihash_enum(const sihash *map, sihash_enum_func enum_func)
{
	unsigned int i, j, n, m;
	Bucket *bucket;
	Pair *pair;

	if (map == NULL) {
		return 0;
	}
	if (enum_func == NULL) {
		return 0;
	}
	bucket = map->buckets;
	n = map->count;
	i = 0;
	while (i < n) {
		pair = bucket->pairs;
		m = bucket->count;
		j = 0;
		while (j < m) {
			enum_func(pair->key, pair->value);
			pair++;
			j++;
		}
		bucket++;
		i++;
	}
	return 1;
}

/*
 * Returns a pair from the bucket that matches the provided key,
 * or null if no such pair exist.
 */
static Pair * get_pair(Bucket *bucket, const char *key)
{
	unsigned int i, n;
	Pair *pair;

	n = bucket->count;
	if (n == 0) {
		return NULL;
	}
	pair = bucket->pairs;
	i = 0;
	while (i < n) {
		if (pair->key != NULL) {
			if (strcmp(pair->key, key) == 0) {
				return pair;
			}
		}
		pair++;
		i++;
	}
	return NULL;
}

/*
 * Returns a hash code for the provided string.
 */
static unsigned long hash(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}
