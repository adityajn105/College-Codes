
(defvar a)
(defvar b)
(defvar c)
(defvar d)


(write-line " Enter two numbers in binary format with prefix #b : ")

	
	(setf a(read))
	(setf b(read))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(+ a b))
				(print "ADDITION in binary: ")
				(format t " ~b" c )
				(print "ADDITION in decimal: ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(- a b))
				(print "SUBTRACTION in binary: ")
				(format t " ~b" c )
				(print "SUBTRACTION in decimal: ")
				(print c))))

 	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a b))
				(print "MULTIPLICATION in binary: ")
				(format t " ~b" c )
				(print "MULTIPLICATION IN DECIMAL: ")
				(print c))))
	
	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a a))
				(print "SQUARE in binary: ")
				(format t " ~b" c )
				(print "SQUARE OF 1st NUMBER  : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* b b b))
				(print "CUBE OF 2ND NUMBER : ")
				(print c))))	


	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(sin a))
				(print "SINE OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(tan a))
				(print "TAN OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(cos a))
				(print "COSINE OF 1ST NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(min a b))
				(print "MINIMUM NUMBER : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(max a b))
				(print "MAXIMUM NUMBER : ")
				(print c))))



