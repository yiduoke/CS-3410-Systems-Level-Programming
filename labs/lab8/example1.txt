
example1.bin:     file format elf32-littleriscv


Disassembly of section .text:

00010094 <printi>:
   10094:	fe010113          	addi	sp,sp,-32
   10098:	00812e23          	sw	s0,28(sp)
   1009c:	02010413          	addi	s0,sp,32
   100a0:	fea42623          	sw	a0,-20(s0)
   100a4:	00100893          	li	a7,1
   100a8:	00000073          	ecall
   100ac:	00000013          	nop
   100b0:	01c12403          	lw	s0,28(sp)
   100b4:	02010113          	addi	sp,sp,32
   100b8:	00008067          	ret

000100bc <prints>:
   100bc:	fe010113          	addi	sp,sp,-32
   100c0:	00812e23          	sw	s0,28(sp)
   100c4:	02010413          	addi	s0,sp,32
   100c8:	fea42623          	sw	a0,-20(s0)
   100cc:	00200893          	li	a7,2
   100d0:	00000073          	ecall
   100d4:	00000013          	nop
   100d8:	01c12403          	lw	s0,28(sp)
   100dc:	02010113          	addi	sp,sp,32
   100e0:	00008067          	ret

000100e4 <putc>:
   100e4:	fe010113          	addi	sp,sp,-32
   100e8:	00812e23          	sw	s0,28(sp)
   100ec:	02010413          	addi	s0,sp,32
   100f0:	00050793          	mv	a5,a0
   100f4:	fef407a3          	sb	a5,-17(s0)
   100f8:	00300893          	li	a7,3
   100fc:	00000073          	ecall
   10100:	00000013          	nop
   10104:	01c12403          	lw	s0,28(sp)
   10108:	02010113          	addi	sp,sp,32
   1010c:	00008067          	ret

00010110 <getc>:
   10110:	ff010113          	addi	sp,sp,-16
   10114:	00812623          	sw	s0,12(sp)
   10118:	01010413          	addi	s0,sp,16
   1011c:	00400893          	li	a7,4
   10120:	00000073          	ecall
   10124:	00050793          	mv	a5,a0
   10128:	00078513          	mv	a0,a5
   1012c:	00c12403          	lw	s0,12(sp)
   10130:	01010113          	addi	sp,sp,16
   10134:	00008067          	ret

00010138 <gets>:
   10138:	fd010113          	addi	sp,sp,-48
   1013c:	02112623          	sw	ra,44(sp)
   10140:	02812423          	sw	s0,40(sp)
   10144:	03010413          	addi	s0,sp,48
   10148:	fca42e23          	sw	a0,-36(s0)
   1014c:	fe042623          	sw	zero,-20(s0)
   10150:	fc1ff0ef          	jal	ra,10110 <getc>
   10154:	fea42423          	sw	a0,-24(s0)
   10158:	fe842703          	lw	a4,-24(s0)
   1015c:	fff00793          	li	a5,-1
   10160:	00f71a63          	bne	a4,a5,10174 <gets+0x3c>
   10164:	fec42783          	lw	a5,-20(s0)
   10168:	00079663          	bnez	a5,10174 <gets+0x3c>
   1016c:	00000793          	li	a5,0
   10170:	0680006f          	j	101d8 <gets+0xa0>
   10174:	fe842703          	lw	a4,-24(s0)
   10178:	fff00793          	li	a5,-1
   1017c:	00f70e63          	beq	a4,a5,10198 <gets+0x60>
   10180:	fe842703          	lw	a4,-24(s0)
   10184:	00a00793          	li	a5,10
   10188:	00f70863          	beq	a4,a5,10198 <gets+0x60>
   1018c:	fe842703          	lw	a4,-24(s0)
   10190:	00d00793          	li	a5,13
   10194:	00f71e63          	bne	a4,a5,101b0 <gets+0x78>
   10198:	fec42783          	lw	a5,-20(s0)
   1019c:	fdc42703          	lw	a4,-36(s0)
   101a0:	00f707b3          	add	a5,a4,a5
   101a4:	00078023          	sb	zero,0(a5)
   101a8:	fdc42783          	lw	a5,-36(s0)
   101ac:	02c0006f          	j	101d8 <gets+0xa0>
   101b0:	fec42783          	lw	a5,-20(s0)
   101b4:	00178713          	addi	a4,a5,1
   101b8:	fee42623          	sw	a4,-20(s0)
   101bc:	00078713          	mv	a4,a5
   101c0:	fdc42783          	lw	a5,-36(s0)
   101c4:	00e787b3          	add	a5,a5,a4
   101c8:	fe842703          	lw	a4,-24(s0)
   101cc:	0ff77713          	andi	a4,a4,255
   101d0:	00e78023          	sb	a4,0(a5)
   101d4:	f7dff06f          	j	10150 <gets+0x18>
   101d8:	00078513          	mv	a0,a5
   101dc:	02c12083          	lw	ra,44(sp)
   101e0:	02812403          	lw	s0,40(sp)
   101e4:	03010113          	addi	sp,sp,48
   101e8:	00008067          	ret

000101ec <rand>:
   101ec:	ff010113          	addi	sp,sp,-16
   101f0:	00812623          	sw	s0,12(sp)
   101f4:	01010413          	addi	s0,sp,16
   101f8:	00600893          	li	a7,6
   101fc:	00000073          	ecall
   10200:	00050793          	mv	a5,a0
   10204:	00078513          	mv	a0,a5
   10208:	00c12403          	lw	s0,12(sp)
   1020c:	01010113          	addi	sp,sp,16
   10210:	00008067          	ret

00010214 <getuser>:
   10214:	fe010113          	addi	sp,sp,-32
   10218:	00812e23          	sw	s0,28(sp)
   1021c:	02010413          	addi	s0,sp,32
   10220:	fea42623          	sw	a0,-20(s0)
   10224:	feb42423          	sw	a1,-24(s0)
   10228:	00700893          	li	a7,7
   1022c:	00000073          	ecall
   10230:	00000013          	nop
   10234:	01c12403          	lw	s0,28(sp)
   10238:	02010113          	addi	sp,sp,32
   1023c:	00008067          	ret

00010240 <readfile>:
   10240:	fe010113          	addi	sp,sp,-32
   10244:	00812e23          	sw	s0,28(sp)
   10248:	02010413          	addi	s0,sp,32
   1024c:	fea42623          	sw	a0,-20(s0)
   10250:	feb42423          	sw	a1,-24(s0)
   10254:	fec42223          	sw	a2,-28(s0)
   10258:	00800893          	li	a7,8
   1025c:	00000073          	ecall
   10260:	00050793          	mv	a5,a0
   10264:	00078513          	mv	a0,a5
   10268:	01c12403          	lw	s0,28(sp)
   1026c:	02010113          	addi	sp,sp,32
   10270:	00008067          	ret

00010274 <writefile>:
   10274:	fe010113          	addi	sp,sp,-32
   10278:	00812e23          	sw	s0,28(sp)
   1027c:	02010413          	addi	s0,sp,32
   10280:	fea42623          	sw	a0,-20(s0)
   10284:	feb42423          	sw	a1,-24(s0)
   10288:	fec42223          	sw	a2,-28(s0)
   1028c:	00900893          	li	a7,9
   10290:	00000073          	ecall
   10294:	00050793          	mv	a5,a0
   10298:	00078513          	mv	a0,a5
   1029c:	01c12403          	lw	s0,28(sp)
   102a0:	02010113          	addi	sp,sp,32
   102a4:	00008067          	ret

000102a8 <exit>:
   102a8:	fe010113          	addi	sp,sp,-32
   102ac:	00812e23          	sw	s0,28(sp)
   102b0:	02010413          	addi	s0,sp,32
   102b4:	fea42623          	sw	a0,-20(s0)
   102b8:	00a00893          	li	a7,10
   102bc:	00000073          	ecall
   102c0:	0000006f          	j	102c0 <exit+0x18>

000102c4 <_start>:
   102c4:	fd010113          	addi	sp,sp,-48
   102c8:	02112623          	sw	ra,44(sp)
   102cc:	02812423          	sw	s0,40(sp)
   102d0:	03010413          	addi	s0,sp,48
   102d4:	fca42e23          	sw	a0,-36(s0)
   102d8:	fcb42c23          	sw	a1,-40(s0)
   102dc:	fd842583          	lw	a1,-40(s0)
   102e0:	fdc42503          	lw	a0,-36(s0)
   102e4:	090000ef          	jal	ra,10374 <main>
   102e8:	fea42623          	sw	a0,-20(s0)
   102ec:	fec42503          	lw	a0,-20(s0)
   102f0:	fb9ff0ef          	jal	ra,102a8 <exit>
   102f4:	00000013          	nop
   102f8:	02c12083          	lw	ra,44(sp)
   102fc:	02812403          	lw	s0,40(sp)
   10300:	03010113          	addi	sp,sp,48
   10304:	00008067          	ret

00010308 <weird_function>:
   10308:	fd010113          	addi	sp,sp,-48
   1030c:	02812623          	sw	s0,44(sp)
   10310:	03010413          	addi	s0,sp,48
   10314:	fca42e23          	sw	a0,-36(s0)
   10318:	fcb42c23          	sw	a1,-40(s0)
   1031c:	fe042423          	sw	zero,-24(s0)
   10320:	fe042623          	sw	zero,-20(s0)
   10324:	0300006f          	j	10354 <weird_function+0x4c>
   10328:	fec42783          	lw	a5,-20(s0)
   1032c:	00279793          	slli	a5,a5,0x2
   10330:	fdc42703          	lw	a4,-36(s0)
   10334:	00f707b3          	add	a5,a4,a5
   10338:	0007a783          	lw	a5,0(a5)
   1033c:	fe842703          	lw	a4,-24(s0)
   10340:	00f707b3          	add	a5,a4,a5
   10344:	fef42423          	sw	a5,-24(s0)
   10348:	fec42783          	lw	a5,-20(s0)
   1034c:	00178793          	addi	a5,a5,1
   10350:	fef42623          	sw	a5,-20(s0)
   10354:	fec42703          	lw	a4,-20(s0)
   10358:	fd842783          	lw	a5,-40(s0)
   1035c:	fcf746e3          	blt	a4,a5,10328 <weird_function+0x20>
   10360:	fe842783          	lw	a5,-24(s0)
   10364:	00078513          	mv	a0,a5
   10368:	02c12403          	lw	s0,44(sp)
   1036c:	03010113          	addi	sp,sp,48
   10370:	00008067          	ret

00010374 <main>:
   10374:	fd010113          	addi	sp,sp,-48
   10378:	02112623          	sw	ra,44(sp)
   1037c:	02812423          	sw	s0,40(sp)
   10380:	03010413          	addi	s0,sp,48
   10384:	fca42e23          	sw	a0,-36(s0)
   10388:	fcb42c23          	sw	a1,-40(s0)
   1038c:	00700593          	li	a1,7
   10390:	000117b7          	lui	a5,0x11
   10394:	3e478513          	addi	a0,a5,996 # 113e4 <a>
   10398:	f71ff0ef          	jal	ra,10308 <weird_function>
   1039c:	fea42623          	sw	a0,-20(s0)
   103a0:	000107b7          	lui	a5,0x10
   103a4:	3d878513          	addi	a0,a5,984 # 103d8 <main+0x64>
   103a8:	d15ff0ef          	jal	ra,100bc <prints>
   103ac:	fec42503          	lw	a0,-20(s0)
   103b0:	ce5ff0ef          	jal	ra,10094 <printi>
   103b4:	000107b7          	lui	a5,0x10
   103b8:	3e078513          	addi	a0,a5,992 # 103e0 <main+0x6c>
   103bc:	d01ff0ef          	jal	ra,100bc <prints>
   103c0:	00000793          	li	a5,0
   103c4:	00078513          	mv	a0,a5
   103c8:	02c12083          	lw	ra,44(sp)
   103cc:	02812403          	lw	s0,40(sp)
   103d0:	03010113          	addi	sp,sp,48
   103d4:	00008067          	ret
