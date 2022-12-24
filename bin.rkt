#lang racket

(define (binstr->ascii blob)
  (let ([num-bytes (/ (string-length blob) 8)])
    (list->string (map
		   (lambda (x) (integer->char (string->number
				 (substring blob (* x 8) (* (+ x 1) 8)) 2)))
		   (range 0 num-bytes)))))

(binstr->ascii "010000010100001001000011")
