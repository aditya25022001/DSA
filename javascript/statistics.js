class Statistics {
    
    #x_values;
    #y_values;
    
    constructor(x_values, y_values = undefined) {
        this.#x_values = x_values;
        this.#y_values = y_values !== undefined && y_values;
    }

    average = () => {
        return {
            x_avg: this.#x_values.reduce((acc, item) => { return acc + item; }) / this.#x_values.length,
            y_avg: this.#y_values && this.#y_values.reduce((acc, item) => { return acc + item; }) / this.#y_values.length
        };
    };
}
