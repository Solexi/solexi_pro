class Calculator
{ 
    constructor(previousOperandTextElement, currentOperandTextElement)
    {
        this.previousOperandTextElement = previousOperandTextElement
        this.currentOperandTextElement = currentOperandTextElement
        this.clear()
    }
    clear()
    {
        this.currentOperand = ''
        this.previousOperand = ''
        this.operation = undefined
    }

    delete() 
    {
        this.currentOperand = this.currentOperand.toString().slice(0, -1)
    }

    appendNumber(number)
    {
        if(number === '.' && this.currentOperand.includes('.'))return
        this.currentOperand = this.currentOperand.toString() + number.toString()
    }

    chooseOperation(operation)
    {
        if(this.currentOperand === '') return
        if(this.previousOperand !=='')
        {
            this.compute()
        }
        this.operation = operation
        this.previousOperand = this.currentOperand
        this.currentOperand = ''
    }

    compute()
    {
        let computation
        const prev = parseFloat(this.previousOperand)
        const current = parseFloat(this.currentOperand)
        if(isNaN(prev) || isNaN (current)) 
        return
        switch (this.operation){
            case '+':
                computation = prev + current
                break
            case '-':
                computation = prev - current
                break
            case 'x':
                computation = prev * current
                break
            case '÷':
                computation = prev / current
                break
            case '±':
                computation = prev + current & prev - current
            default:
                return 
        }
        this.currentOperand = computation
        this.operation = undefined
        this.previousOperand = ''
    }
    getDisplayNumber(number)
    {
        const stringNumber = number.toString()
        const integerDigits = parseFloat(stringNumber.split('.')[0])
        const decimalDigits = stringNumber.split('.')[1]
        let integerDisplay
        if (isNaN(integerDigits))
        {
            integerDisplay = ''
        }
        else
        {
            integerDisplay = integerDigits.toLocaleString('en', {maximumFractionDigits: 0})
        }
        if (decimalDigits != null)
        {
            return `${integerDisplay}.${decimalDigits}`
        }
        else
        {
            return integerDisplay
        }
    }
    updateDisplay()
    {
        this.currentOperandTextElement.innerText = this.getDisplayNumber(this.currentOperand)
        if(this.operation != null)
        {
            this.previousOperandTextElement.innerText = 
                `${this.getDisplayNumber(this.previousOperand)} ${this.operation}`
        }
        else{
            this.previousOperandTextElement.innerText = ''
        }
    }
}


const numberButtons = document.querySelectorAll('.number');
const operationButtons = document.querySelectorAll('.operation') 
const equalsButton = document.querySelector('.equals')
const deleteButton = document.querySelector('.delete')
const allClearButton = document.querySelector('.clear')
const previousOperandTextElement = document.querySelector('[data-prev]')
const currentOperandTextElement = document.querySelector('[data-curr]')
const calculator = new Calculator(previousOperandTextElement, currentOperandTextElement)

/*const hourHand = document.querySelector('.hour')
const minuteHand = document.querySelector('.minute')
const timeUpdate = () => {
const currentTime = new Date()
    let currentHour = current.getHours()
    const currentMin = currentTime.getMinutes()

    if(currentHour > 12){
        currentHour -= 12
    }
    hourHand.textContent = currentHour.toString()
    minuteHand = currentMin.toString.padStart(2, '0')
}
setInterval(timeUpdate, 1000)
timeUpdate()*/

numberButtons.forEach(button => {
    button.addEventListener('click', () => {
        calculator.appendNumber(button.innerText)
        calculator.updateDisplay()
    })
})

operationButtons.forEach(button => {
    button.addEventListener('click', () => {
        calculator.chooseOperation(button.innerText)
        calculator.updateDisplay()
    })
})

equalsButton.addEventListener('click', button => {
    calculator.compute()
    calculator.updateDisplay()
})

allClearButton.addEventListener('click', button => {
    calculator.clear()
    calculator.updateDisplay()
})

deleteButton.addEventListener('click', button => {
    calculator.delete()
    calculator.updateDisplay()
})