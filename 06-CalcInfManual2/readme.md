# Calculadora notacion Infija: Construcción Manual

---

### Gramática léxica 

<token> -> uno de <identificador> <constante> <operador>
    <identificador> -> <letra>
    <constante> -> <dígito>
    	<letra> -> una de a-z A-Z (a-z|A-Z)*
    	<dígito> -> uno de 0-9
    	<operador> -> uno de <adición> <producto>
    		<adición> +
    		<producto> *

---

### Gramática sintáctica 🔗


<expresión> -> <operando> <operador> <operando> (<operador> <operando>)*
    <operando> -> <identificador> <constante>
    <operador> -> <adición> <producto>


---

### Automata Finito Deterministico

<img src="/06-CalcInfManual/imgs/afd.png" alt="Autómata finito determinístico" style="zoom:30%;" />

---

