	.file	"main.c"
	.globl	_head
	.bss
	.align 4
_head:
	.space 4
	.section .rdata,"dr"
LC0:
	.ascii "Memory allocation failed.\0"
	.text
	.globl	_createNode
	.def	_createNode;	.scl	2;	.type	32;	.endef
_createNode:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$8, (%esp)
	call	_malloc
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L2
	movl	$LC0, (%esp)
	call	_puts
	movl	$1, (%esp)
	call	_exit
L2:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_insertAtBeginning
	.def	_insertAtBeginning;	.scl	2;	.type	32;	.endef
_insertAtBeginning:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_createNode
	movl	%eax, -12(%ebp)
	movl	_head, %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, _head
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	_insertAtEnd
	.def	_insertAtEnd;	.scl	2;	.type	32;	.endef
_insertAtEnd:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_createNode
	movl	%eax, -16(%ebp)
	movl	_head, %eax
	testl	%eax, %eax
	jne	L6
	movl	-16(%ebp), %eax
	movl	%eax, _head
	jmp	L10
L6:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	jmp	L8
L9:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L8:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L9
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%eax)
L10:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.section .rdata,"dr"
	.align 4
LC1:
	.ascii "Node with data %d not found in the list.\12\0"
	.text
	.globl	_insertAfterNode
	.def	_insertAfterNode;	.scl	2;	.type	32;	.endef
_insertAfterNode:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	jmp	L12
L14:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L12:
	cmpl	$0, -12(%ebp)
	je	L13
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L14
L13:
	cmpl	$0, -12(%ebp)
	je	L15
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_createNode
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%eax)
	jmp	L17
L15:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
L17:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.section .rdata,"dr"
LC2:
	.ascii "The list is empty.\0"
	.text
	.globl	_insertBeforeNode
	.def	_insertBeforeNode;	.scl	2;	.type	32;	.endef
_insertBeforeNode:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	testl	%eax, %eax
	jne	L19
	movl	$LC2, (%esp)
	call	_puts
	jmp	L18
L19:
	movl	_head, %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L21
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_insertAtBeginning
	jmp	L18
L21:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L22
L24:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L22:
	cmpl	$0, -12(%ebp)
	je	L23
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L24
L23:
	cmpl	$0, -12(%ebp)
	je	L25
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_createNode
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 4(%eax)
	jmp	L18
L25:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
L18:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC3:
	.ascii "Invalid position.\0"
LC4:
	.ascii "Position out of range.\0"
	.text
	.globl	_insertAtPosition
	.def	_insertAtPosition;	.scl	2;	.type	32;	.endef
_insertAtPosition:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	cmpl	$0, 8(%ebp)
	jg	L27
	movl	$LC3, (%esp)
	call	_puts
	jmp	L26
L27:
	cmpl	$1, 8(%ebp)
	jne	L29
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_insertAtBeginning
	jmp	L26
L29:
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_createNode
	movl	%eax, -20(%ebp)
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	movl	$1, -16(%ebp)
	jmp	L30
L32:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	addl	$1, -16(%ebp)
L30:
	cmpl	$0, -12(%ebp)
	je	L31
	movl	8(%ebp), %eax
	subl	$1, %eax
	cmpl	-16(%ebp), %eax
	jg	L32
L31:
	cmpl	$0, -12(%ebp)
	jne	L33
	movl	$LC4, (%esp)
	call	_puts
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	jmp	L26
L33:
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-20(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%edx, 4(%eax)
L26:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_searchNode
	.def	_searchNode;	.scl	2;	.type	32;	.endef
_searchNode:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	_head, %eax
	movl	%eax, -4(%ebp)
	jmp	L35
L38:
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L36
	movl	-4(%ebp), %eax
	jmp	L37
L36:
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -4(%ebp)
L35:
	cmpl	$0, -4(%ebp)
	jne	L38
	movl	$0, %eax
L37:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.globl	_deleteAtBeginning
	.def	_deleteAtBeginning;	.scl	2;	.type	32;	.endef
_deleteAtBeginning:
LFB21:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	testl	%eax, %eax
	jne	L40
	movl	$LC2, (%esp)
	call	_puts
	jmp	L39
L40:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	movl	_head, %eax
	movl	4(%eax), %eax
	movl	%eax, _head
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L39:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE21:
	.globl	_deleteAtEnd
	.def	_deleteAtEnd;	.scl	2;	.type	32;	.endef
_deleteAtEnd:
LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	testl	%eax, %eax
	jne	L43
	movl	$LC2, (%esp)
	call	_puts
	jmp	L42
L43:
	movl	_head, %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L45
	movl	_head, %eax
	movl	%eax, (%esp)
	call	_free
	movl	$0, _head
	jmp	L42
L45:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	jmp	L46
L47:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L46:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L47
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	_free
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
L42:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE22:
	.section .rdata,"dr"
	.align 4
LC5:
	.ascii "Node with data %d not found or no node after it.\12\0"
	.text
	.globl	_deleteAfterNode
	.def	_deleteAfterNode;	.scl	2;	.type	32;	.endef
_deleteAfterNode:
LFB23:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	jmp	L49
L51:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L49:
	cmpl	$0, -12(%ebp)
	je	L50
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L51
L50:
	cmpl	$0, -12(%ebp)
	je	L52
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	L53
L52:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	jmp	L48
L53:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L48:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE23:
	.section .rdata,"dr"
	.align 4
LC6:
	.ascii "Cannot delete a node before the head of the list.\0"
	.text
	.globl	_deleteBeforeNode
	.def	_deleteBeforeNode;	.scl	2;	.type	32;	.endef
_deleteBeforeNode:
LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	testl	%eax, %eax
	jne	L56
	movl	$LC2, (%esp)
	call	_puts
	jmp	L55
L56:
	movl	_head, %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L58
	movl	$LC6, (%esp)
	call	_puts
	jmp	L55
L58:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L59
L61:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L59:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	L60
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L61
L60:
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	je	L62
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L62
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
	cmpl	$0, -16(%ebp)
	jne	L63
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, _head
	jmp	L64
L63:
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, 4(%eax)
L64:
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
	jmp	L55
L62:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
L55:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE24:
	.globl	_deleteParticularNode
	.def	_deleteParticularNode;	.scl	2;	.type	32;	.endef
_deleteParticularNode:
LFB25:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	testl	%eax, %eax
	jne	L66
	movl	$LC2, (%esp)
	call	_puts
	jmp	L65
L66:
	movl	_head, %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L68
	call	_deleteAtBeginning
	jmp	L65
L68:
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	movl	$0, -16(%ebp)
	jmp	L69
L71:
	movl	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L69:
	cmpl	$0, -12(%ebp)
	je	L70
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jne	L71
L70:
	cmpl	$0, -12(%ebp)
	jne	L72
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	jmp	L65
L72:
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-16(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	_free
L65:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE25:
	.section .rdata,"dr"
LC7:
	.ascii "Linked List: \0"
LC8:
	.ascii "%d \0"
	.text
	.globl	_printList
	.def	_printList;	.scl	2;	.type	32;	.endef
_printList:
LFB26:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_head, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	jne	L74
	movl	$LC2, (%esp)
	call	_puts
	jmp	L78
L74:
	movl	$LC7, (%esp)
	call	_printf
	jmp	L76
L77:
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
L76:
	cmpl	$0, -12(%ebp)
	jne	L77
	movl	$10, (%esp)
	call	_putchar
L78:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE26:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC9:
	.ascii "\12Menu:\0"
LC10:
	.ascii "1. Insert at the beginning\0"
LC11:
	.ascii "2. Insert at the end\0"
	.align 4
LC12:
	.ascii "3. Insert after a particular node\0"
	.align 4
LC13:
	.ascii "4. Insert before a particular node\0"
	.align 4
LC14:
	.ascii "5. Insert at a specific position\0"
	.align 4
LC15:
	.ascii "6. Search for a particular node\0"
LC16:
	.ascii "7. Return a particular node\0"
LC17:
	.ascii "8. Delete at the beginning\0"
LC18:
	.ascii "9. Delete at the end\0"
	.align 4
LC19:
	.ascii "10. Delete after a particular node\0"
	.align 4
LC20:
	.ascii "11. Delete before a particular node\0"
LC21:
	.ascii "12. Delete a particular node\0"
LC22:
	.ascii "13. Print list\0"
LC23:
	.ascii "14. Exit\0"
LC24:
	.ascii "Enter your choice: \0"
LC25:
	.ascii "%d\0"
	.align 4
LC26:
	.ascii "Enter data to insert at the beginning: \0"
	.align 4
LC27:
	.ascii "Enter data to insert at the end: \0"
	.align 4
LC28:
	.ascii "Enter data of the node after which to insert: \0"
LC29:
	.ascii "Enter data to insert: \0"
	.align 4
LC30:
	.ascii "Enter data of the node before which to insert: \0"
	.align 4
LC31:
	.ascii "Enter the position to insert at: \0"
LC32:
	.ascii "Enter data to search for: \0"
LC33:
	.ascii "Node with data %d found.\12\0"
LC34:
	.ascii "Node with data %d not found.\12\0"
	.align 4
LC35:
	.ascii "Enter data of the node to return: \0"
	.align 4
LC36:
	.ascii "Node at the beginning deleted.\0"
LC37:
	.ascii "Node at the end deleted.\0"
	.align 4
LC38:
	.ascii "Enter data of the node after which to delete: \0"
	.align 4
LC39:
	.ascii "Enter data of the node before which to delete: \0"
	.align 4
LC40:
	.ascii "Enter data of the node to delete: \0"
	.align 4
LC41:
	.ascii "Invalid choice. Please try again.\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB27:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
L101:
	movl	$LC9, (%esp)
	call	_puts
	movl	$LC10, (%esp)
	call	_puts
	movl	$LC11, (%esp)
	call	_puts
	movl	$LC12, (%esp)
	call	_puts
	movl	$LC13, (%esp)
	call	_puts
	movl	$LC14, (%esp)
	call	_puts
	movl	$LC15, (%esp)
	call	_puts
	movl	$LC16, (%esp)
	call	_puts
	movl	$LC17, (%esp)
	call	_puts
	movl	$LC18, (%esp)
	call	_puts
	movl	$LC19, (%esp)
	call	_puts
	movl	$LC20, (%esp)
	call	_puts
	movl	$LC21, (%esp)
	call	_puts
	movl	$LC22, (%esp)
	call	_puts
	movl	$LC23, (%esp)
	call	_puts
	movl	$LC24, (%esp)
	call	_printf
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	40(%esp), %eax
	cmpl	$14, %eax
	ja	L80
	movl	L82(,%eax,4), %eax
	jmp	*%eax
	.section .rdata,"dr"
	.align 4
L82:
	.long	L80
	.long	L81
	.long	L83
	.long	L84
	.long	L85
	.long	L86
	.long	L87
	.long	L88
	.long	L89
	.long	L90
	.long	L91
	.long	L92
	.long	L93
	.long	L94
	.long	L95
	.text
L81:
	movl	$LC26, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	_insertAtBeginning
	jmp	L96
L83:
	movl	$LC27, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	_insertAtEnd
	jmp	L96
L84:
	movl	$LC28, (%esp)
	call	_printf
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	$LC29, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %edx
	movl	28(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_insertAfterNode
	jmp	L96
L85:
	movl	$LC30, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	$LC29, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %edx
	movl	24(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_insertBeforeNode
	jmp	L96
L86:
	movl	$LC31, (%esp)
	call	_printf
	leal	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	$LC29, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %edx
	movl	32(%esp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_insertAtPosition
	jmp	L96
L87:
	movl	$LC32, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	_searchNode
	movl	%eax, 44(%esp)
	cmpl	$0, 44(%esp)
	je	L97
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC33, (%esp)
	call	_printf
	jmp	L96
L97:
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC34, (%esp)
	call	_printf
	jmp	L96
L88:
	movl	$LC35, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	_searchNode
	movl	%eax, 44(%esp)
	cmpl	$0, 44(%esp)
	je	L99
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC33, (%esp)
	call	_printf
	jmp	L96
L99:
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC34, (%esp)
	call	_printf
	jmp	L96
L89:
	call	_deleteAtBeginning
	movl	$LC36, (%esp)
	call	_puts
	jmp	L96
L90:
	call	_deleteAtEnd
	movl	$LC37, (%esp)
	call	_puts
	jmp	L96
L91:
	movl	$LC38, (%esp)
	call	_printf
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	_deleteAfterNode
	jmp	L96
L92:
	movl	$LC39, (%esp)
	call	_printf
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	24(%esp), %eax
	movl	%eax, (%esp)
	call	_deleteBeforeNode
	jmp	L96
L93:
	movl	$LC40, (%esp)
	call	_printf
	leal	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC25, (%esp)
	call	_scanf
	movl	36(%esp), %eax
	movl	%eax, (%esp)
	call	_deleteParticularNode
	jmp	L96
L94:
	call	_printList
	jmp	L96
L95:
	movl	$0, (%esp)
	call	_exit
L80:
	movl	$LC41, (%esp)
	call	_puts
	nop
L96:
	jmp	L101
	.cfi_endproc
LFE27:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
