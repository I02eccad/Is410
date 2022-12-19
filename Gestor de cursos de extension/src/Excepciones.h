#ifndef EXCEPCIONES_H_
#define EXCEPCIONES_H_

#include <exception>

struct NoAuthorizado : public exception {
   const char * what () const throw () {
      return "No tienes la authorización para esta funcionalidad!";
   }
};

struct CredencialesIncorrectas : public exception {
   const char * what () const throw () {
      return "Nombre o contraseña son incorrectas!";
   }
};

struct CursoNoEncontrado : public exception {
   const char * what () const throw () {
      return "Curso dado no existe!";
   }
};

struct SuperadoIntentos : public exception {
   const char * what () const throw () {
      return "Ha superado el número de intentos, póngase en contacto con el administrador!";
   }
};

struct NoExiste : public exception {
   const char * what () const throw () {
      return "El recurso solicitado no existe!";
   }
};

struct YaSuscrito : public exception {
   const char * what () const throw () {
      return "No puedes subscribir en este curso porqué ya estás suscrito!";
   }
};

struct NoSuscrito : public exception {
   const char * what () const throw () {
      return "No estás suscrito en este curso!";
   }
};

struct RecursoNoExiste : public exception {
   const char * what () const throw () {
      return "El recurso que intenta eliminar no existe!";
   }
};

struct ArgsIncorrectos : public exception {
   const char * what () const throw () {
      return "Argumentos del comando no son de la forma correcta!";
   }
};

#endif /* EXCEPCIONES_H_ */

