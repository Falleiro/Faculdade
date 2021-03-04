# Trabalho-APC1
Este é meu trabalho de APC1, em que tive que elaborar um programa em liguagem de e programação C que simula a propagação de vírus em três situações
distintas: Sem isolamento social, com isolamento social parcial e com isolamento social máximo.

Para todos os casos, a simulação deveria conter uma matriz de 100 por 100 com 5000 indivíduos
e deveria ser atualizadas a cada 2 segundos. A disseminação da doença ocorre com 75% de
chance de infecção no raio de 3 a volta do indivíduo

O padrão de movimentação e o local de início de cada indivíduo são aleatórios
considerando deslocamento unitário para um dos lados. Os indivíduos não se movimentam
na diagonal. A seguir é descrito algumas regras a mais para a movimentação dos indivíduos nos
cenários propostos

Sem isolamento social: Todos os indivíduos sempre se movem a cada 2 segundos;
Isolamento Social Parcial: Apenas 50% dos indivíduos se move a cada 2 segundos;
Isolamento Social Máximo: Apenas 20% dos indivíduos se move a cada 2 segundos;

Um indivíduo infectado leva 36 segundos para se curar e enquanto está doente
não se movimento e propaga o vírus. A cura ocorre em 90% dos contaminados e aqueles que
não se curam morrem e passam a não transmitir mais a doença e devem ser removidos da
matriz.

Ao final 3600 segundos da simulação iniciada, apresenta-se a quantidade total de
infecções do vírus, a quantidade de indivíduos únicos infectados para cada 2 segundo da
simulação e quantidade total de indivíduos mortos.

Considere que a doença irá começar com 5 indivíduos infectados e que leva 60 segundos após a
infecção para o indivíduo ficar doente, propagando a doença enquanto isso.
